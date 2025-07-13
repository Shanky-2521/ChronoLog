#include "chronolog/memtable.h"
#include <chrono>

namespace chronolog {

Memtable::Memtable(size_t max_size_bytes)
    : approximate_size_bytes_(0)
    , max_size_bytes_(max_size_bytes)
    , immutable_(false) {
}

bool Memtable::put(const Key& key, const Value& value, Timestamp timestamp) {
    if (immutable_.load()) {
        return false;
    }
    
    if (timestamp == 0) {
        timestamp = get_current_timestamp();
    }
    
    std::unique_lock<std::shared_mutex> lock(mutex_);
    
    Entry new_entry(key, value, EntryType::PUT, timestamp);
    
    auto it = entries_.find(key);
    if (it != entries_.end()) {
        Entry old_entry = it->second;
        it->second = new_entry;
        update_size(old_entry, new_entry);
    } else {
        entries_[key] = new_entry;
        approximate_size_bytes_.fetch_add(estimate_entry_size(new_entry));
    }
    
    return true;
}

bool Memtable::remove(const Key& key, Timestamp timestamp) {
    if (immutable_.load()) {
        return false;
    }
    
    if (timestamp == 0) {
        timestamp = get_current_timestamp();
    }
    
    std::unique_lock<std::shared_mutex> lock(mutex_);
    
    Entry tombstone_entry(key, "", EntryType::DELETE, timestamp);
    
    auto it = entries_.find(key);
    if (it != entries_.end()) {
        Entry old_entry = it->second;
        it->second = tombstone_entry;
        update_size(old_entry, tombstone_entry);
    } else {
        entries_[key] = tombstone_entry;
        approximate_size_bytes_.fetch_add(estimate_entry_size(tombstone_entry));
    }
    
    return true;
}

std::optional<Value> Memtable::get(const Key& key) const {
    std::shared_lock<std::shared_mutex> lock(mutex_);
    
    auto it = entries_.find(key);
    if (it != entries_.end()) {
        const Entry& entry = it->second;
        if (entry.is_tombstone()) {
            return std::nullopt;
        }
        return entry.value;
    }
    
    return std::nullopt;
}

std::optional<Entry> Memtable::get_entry(const Key& key) const {
    std::shared_lock<std::shared_mutex> lock(mutex_);
    
    auto it = entries_.find(key);
    if (it != entries_.end()) {
        return it->second;
    }
    
    return std::nullopt;
}

bool Memtable::should_flush() const {
    return approximate_size_bytes_.load() >= max_size_bytes_;
}

size_t Memtable::size_bytes() const {
    return approximate_size_bytes_.load();
}

size_t Memtable::entry_count() const {
    std::shared_lock<std::shared_mutex> lock(mutex_);
    return entries_.size();
}

bool Memtable::empty() const {
    std::shared_lock<std::shared_mutex> lock(mutex_);
    return entries_.empty();
}

void Memtable::clear() {
    std::unique_lock<std::shared_mutex> lock(mutex_);
    entries_.clear();
    approximate_size_bytes_.store(0);
}

void Memtable::make_immutable() {
    immutable_.store(true);
}

bool Memtable::is_immutable() const {
    return immutable_.load();
}

std::vector<Entry> Memtable::get_all_entries() const {
    std::shared_lock<std::shared_mutex> lock(mutex_);
    
    std::vector<Entry> result;
    result.reserve(entries_.size());
    
    for (const auto& pair : entries_) {
        result.push_back(pair.second);
    }
    
    return result;
}

std::vector<Entry> Memtable::get_range(const Key& start_key, const Key& end_key) const {
    std::shared_lock<std::shared_mutex> lock(mutex_);
    
    std::vector<Entry> result;
    
    auto start_it = entries_.lower_bound(start_key);
    auto end_it = entries_.lower_bound(end_key);
    
    for (auto it = start_it; it != end_it; ++it) {
        result.push_back(it->second);
    }
    
    return result;
}

Timestamp Memtable::get_current_timestamp() const {
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    return std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
}

size_t Memtable::estimate_entry_size(const Entry& entry) const {
    return entry.key.size() + entry.value.size() + sizeof(Entry) + 32;
}

void Memtable::update_size(const Entry& old_entry, const Entry& new_entry) {
    size_t old_size = estimate_entry_size(old_entry);
    size_t new_size = estimate_entry_size(new_entry);
    
    if (new_size >= old_size) {
        approximate_size_bytes_.fetch_add(new_size - old_size);
    } else {
        approximate_size_bytes_.fetch_sub(old_size - new_size);
    }
}

} // namespace chronolog

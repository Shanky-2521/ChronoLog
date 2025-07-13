#pragma once

#include "types.h"
#include <map>
#include <mutex>
#include <shared_mutex>
#include <atomic>
#include <optional>

namespace chronolog {

/**
 * In-memory sorted data structure for LSM-Tree
 * Uses a balanced BST for O(log n) operations
 */
class Memtable {
public:
    explicit Memtable(size_t max_size_bytes = config::DEFAULT_MEMTABLE_SIZE_BYTES);
    ~Memtable() = default;
    
    // Disable copy and move due to mutex
    Memtable(const Memtable&) = delete;
    Memtable& operator=(const Memtable&) = delete;
    Memtable(Memtable&&) = delete;
    Memtable& operator=(Memtable&&) = delete;
    
    // Core operations
    bool put(const Key& key, const Value& value, Timestamp timestamp = 0);
    bool remove(const Key& key, Timestamp timestamp = 0);
    std::optional<Value> get(const Key& key) const;
    std::optional<Entry> get_entry(const Key& key) const;
    
    // Size and capacity management
    bool should_flush() const;
    size_t size_bytes() const;
    size_t entry_count() const;
    bool empty() const;
    void clear();
    
    // Immutability control
    void make_immutable();
    bool is_immutable() const;
    
    // Iteration and range queries
    std::vector<Entry> get_all_entries() const;
    std::vector<Entry> get_range(const Key& start_key, const Key& end_key) const;

private:
    std::map<Key, Entry> entries_;
    mutable std::shared_mutex mutex_;
    std::atomic<size_t> approximate_size_bytes_;
    const size_t max_size_bytes_;
    std::atomic<bool> immutable_;
    
    Timestamp get_current_timestamp() const;
    size_t estimate_entry_size(const Entry& entry) const;
    void update_size(const Entry& old_entry, const Entry& new_entry);
};

} // namespace chronolog

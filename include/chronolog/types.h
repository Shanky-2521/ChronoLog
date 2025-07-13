#pragma once

#include <string>
#include <vector>
#include <memory>
#include <cstdint>

namespace chronolog {

// Basic types
using Key = std::string;
using Value = std::string;
using Timestamp = uint64_t;
using FileId = uint64_t;

// Entry types for operations
enum class EntryType : uint8_t {
    PUT = 0,
    DELETE = 1
};

// Key-value entry with metadata
struct Entry {
    Key key;
    Value value;
    EntryType type;
    Timestamp timestamp;
    
    Entry() = default;
    Entry(const Key& k, const Value& v, EntryType t = EntryType::PUT, Timestamp ts = 0)
        : key(k), value(v), type(t), timestamp(ts) {}
    
    bool is_tombstone() const {
        return type == EntryType::DELETE;
    }
    
    bool operator<(const Entry& other) const {
        if (key != other.key) {
            return key < other.key;
        }
        return timestamp > other.timestamp;
    }
    
    bool operator==(const Entry& other) const {
        return key == other.key && timestamp == other.timestamp;
    }
};

// Configuration constants
namespace config {
    constexpr size_t DEFAULT_MEMTABLE_SIZE_BYTES = 4 * 1024 * 1024;  // 4MB
    constexpr size_t DEFAULT_BLOCK_SIZE_BYTES = 4 * 1024;            // 4KB
    constexpr size_t DEFAULT_BLOOM_FILTER_BITS_PER_KEY = 10;
    constexpr const char* DEFAULT_DATA_DIR = "./data";
    constexpr const char* SSTABLE_FILE_EXTENSION = ".sst";
}

// Result type for operations
template<typename T>
class Result {
private:
    bool success_;
    T value_;
    std::string error_message_;

public:
    // Private constructors to avoid ambiguity
    Result(bool success, T value, const std::string& error) 
        : success_(success), value_(std::move(value)), error_message_(error) {}
    
    // Static factory methods
    static Result success(T value) {
        return Result(true, std::move(value), "");
    }
    
    static Result error(const std::string& error_msg) {
        return Result(false, T{}, error_msg);
    }
    
    bool is_success() const { return success_; }
    bool is_error() const { return !success_; }
    
    const T& value() const { return value_; }
    const std::string& error() const { return error_message_; }
    
    T& value() { return value_; }
};

// Common result types
using GetResult = Result<Value>;
using PutResult = Result<bool>;

} // namespace chronolog

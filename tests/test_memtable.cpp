#include "chronolog/memtable.h"
#include <iostream>
#include <cassert>
#include <string>

using namespace chronolog;

void test_basic_operations() {
    std::cout << "Testing basic operations..." << std::endl;
    
    Memtable memtable(1024);
    
    // Test put and get
    assert(memtable.put("key1", "value1"));
    auto result = memtable.get("key1");
    assert(result.has_value());
    assert(result.value() == "value1");
    
    // Test update
    assert(memtable.put("key1", "updated_value1"));
    result = memtable.get("key1");
    assert(result.has_value());
    assert(result.value() == "updated_value1");
    
    // Test multiple keys
    assert(memtable.put("key2", "value2"));
    assert(memtable.put("key3", "value3"));
    
    assert(memtable.get("key2").value() == "value2");
    assert(memtable.get("key3").value() == "value3");
    assert(memtable.entry_count() == 3);
    
    std::cout << "Basic operations test passed" << std::endl;
}

void test_delete_operations() {
    std::cout << "Testing delete operations..." << std::endl;
    
    Memtable memtable(1024);
    
    assert(memtable.put("key1", "value1"));
    assert(memtable.put("key2", "value2"));
    
    assert(memtable.remove("key1"));
    
    auto result = memtable.get("key1");
    assert(!result.has_value());
    
    auto entry = memtable.get_entry("key1");
    assert(entry.has_value());
    assert(entry.value().is_tombstone());
    
    result = memtable.get("key2");
    assert(result.has_value());
    assert(result.value() == "value2");
    
    std::cout << "Delete operations test passed" << std::endl;
}

void test_range_queries() {
    std::cout << "Testing range queries..." << std::endl;
    
    Memtable memtable(1024);
    
    assert(memtable.put("key5", "value5"));
    assert(memtable.put("key1", "value1"));
    assert(memtable.put("key3", "value3"));
    assert(memtable.put("key2", "value2"));
    assert(memtable.put("key4", "value4"));
    
    auto entries = memtable.get_range("key2", "key5");
    
    assert(entries.size() == 3);
    assert(entries[0].key == "key2");
    assert(entries[1].key == "key3");
    assert(entries[2].key == "key4");
    
    std::cout << "Range queries test passed" << std::endl;
}

void test_size_tracking() {
    std::cout << "Testing size tracking..." << std::endl;
    
    Memtable memtable(100);
    
    assert(memtable.size_bytes() == 0);
    assert(memtable.empty());
    assert(!memtable.should_flush());
    
    assert(memtable.put("key1", "value1"));
    assert(memtable.size_bytes() > 0);
    assert(!memtable.empty());
    
    for (int i = 0; i < 10; ++i) {
        std::string key = "key" + std::to_string(i);
        std::string value = "value" + std::to_string(i);
        memtable.put(key, value);
    }
    
    assert(memtable.should_flush());
    
    std::cout << "Size tracking test passed" << std::endl;
}

void test_immutability() {
    std::cout << "Testing immutability..." << std::endl;
    
    Memtable memtable(1024);
    
    assert(memtable.put("key1", "value1"));
    assert(!memtable.is_immutable());
    
    memtable.make_immutable();
    assert(memtable.is_immutable());
    
    assert(!memtable.put("key2", "value2"));
    assert(!memtable.remove("key1"));
    
    auto result = memtable.get("key1");
    assert(result.has_value());
    assert(result.value() == "value1");
    
    std::cout << "Immutability test passed" << std::endl;
}

int main() {
    std::cout << "Running Memtable tests..." << std::endl;
    
    try {
        test_basic_operations();
        test_delete_operations();
        test_range_queries();
        test_size_tracking();
        test_immutability();
        
        std::cout << "\nAll Memtable tests passed!" << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }
}

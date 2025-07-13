#include "chronolog/memtable.h"
#include <iostream>

using namespace chronolog;

int main() {
    std::cout << "ChronoLog Demo - LSM-Tree Storage Engine" << std::endl;
    std::cout << "=========================================" << std::endl;
    
    Memtable memtable(1024 * 1024);  // 1MB
    
    std::cout << "Created Memtable with 1MB capacity" << std::endl;
    
    // Insert some data
    memtable.put("user:1", "Alice");
    memtable.put("user:2", "Bob");
    memtable.put("user:3", "Charlie");
    
    std::cout << "Inserted 3 users" << std::endl;
    
    // Read data
    auto result = memtable.get("user:2");
    if (result.has_value()) {
        std::cout << "user:2 = " << result.value() << std::endl;
    }
    
    // Update data
    memtable.put("user:2", "Robert");
    result = memtable.get("user:2");
    if (result.has_value()) {
        std::cout << "Updated user:2 = " << result.value() << std::endl;
    }
    
    // Delete data
    memtable.remove("user:3");
    result = memtable.get("user:3");
    if (!result.has_value()) {
        std::cout << "user:3 deleted successfully" << std::endl;
    }
    
    std::cout << "Memtable size: " << memtable.size_bytes() << " bytes" << std::endl;
    std::cout << "Entry count: " << memtable.entry_count() << std::endl;
    
    std::cout << "\nDemo completed successfully!" << std::endl;
    return 0;
}

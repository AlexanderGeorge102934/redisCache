#include "lruCache.h"
#include <iostream>

int main() {
    // Create an LRU cache with a capacity of 2
    lruCache<int, std::string> cache(2);

    // Insert key-value pairs
    cache.put(1, "one");
    cache.put(2, "two");

    // Retrieve values
    std::cout << "Key 1: " << cache.get(1).value_or("not found") << std::endl; // Output: one
    std::cout << "Key 2: " << cache.get(2).value_or("not found") << std::endl; // Output: two

    // Insert another key-value pair (evicts the least recently used key)
    cache.put(3, "three");
    
    
    // Retrieve values
    std::cout << "Key 1: " << cache.get(1).value_or("not found") << std::endl; // Output: not found last element 
    std::cout << "Key 2: " << cache.get(2).value_or("not found") << std::endl;
    std::cout << "Key 3: " << cache.get(3).value_or("not found") << std::endl; // Output: three

    return 0;
}

#include "lruCache.h"
#include 

	
// Constructor definition
template <typename Key, typename Value>
lruCache<Key, Value>::lruCache(const unsigned int& capacity) : size(capacity) {}

template <typename Key, typename Value>
void lruCache<Key,Value>::put(const Key &key, const Value &value){
	if(cacheMap.count(key) == 0){
		// Add to front of list 
		cache.push_front(key);
		cacheMap[key] = {value, cache.begin()};
		
		// Remove LRU from back of list 	
		if(cache.size() > size){
			Key lastElement = cache.back();
			cacheMap.erase(key);
			cache.pop_back();
		}	

		return;	
	}
	
	cacheMap[key].first = value;
	cache.splice(cache.begin(), cache, cacheMap[key].second);



}

// Method to retrieve a value by key
template <typename Key, typename Value>
std::optional<Value> lruCache<Key, Value>::get(const Key& key) {
    // Check if the key exists in the cache
    if (cacheMap.count(key) == 0) {
        return std::nullopt; // Key not found
    }

    // Bring key to front of cache 
    cache.splice(cache.begin(), cache, cacheMap[key].second);

    // Return the value associated with the key
    return cacheMap[key].first;
}

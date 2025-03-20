#include "redisCache.h"
	
// Constructor definition
template <typename Key, typename Value>
redisCache<Key, Value>::redisCache(const unsigned int& capacity) : size(capacity) {}

template <typename Key, typename Value>
void redisCache<Key,Value>::put(const Key &key, const Value &value){
	if(cacheMap.count(key) == 0){
		// Add to front of list 
		cache.push_front(key);
		cacheMap[key] = {value, cache.begin()};
		
		// Remove LRU from back of list 	
		if(cache.size() > size){
			Key lastElement = cache.back();
			cacheMap.erase(lastElement);
			cache.pop_back();
		}	

		return;	
	}
	
	cacheMap[key].first = value;
	cache.splice(cache.begin(), cache, cacheMap[key].second);



}

// Method to retrieve a value by key
template <typename Key, typename Value>
std::optional<Value> redisCache<Key, Value>::get(const Key& key) {
    // Check if the key exists in the cache
    if (cacheMap.count(key) == 0) {
        return std::nullopt; // Key not found
    }

    // Bring key to front of cache 
    cache.splice(cache.begin(), cache, cacheMap[key].second);

    // Return the value associated with the key
    return cacheMap[key].first;
}


template <typename Key, typename Value>
void redisCache<Key,Value>::expire(time_t secondsToExpire, const Key &key){

	// Check to make sure the key exists
	if(cacheMap.count(key) == 0){
		std::cout << "Key: "<< key << "doesn't exist." << std::endl;
		return;
	}

	// Add key to the heap 
	expirationHeap.push({secondsToExpire, key});


}





template class redisCache<int, std::string>;

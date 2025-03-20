#ifndef REDISCACHE_H
#define REDISCACHE_H

#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <utility>
#include <optional>
#include <queue>
#include <time.h>
#include <thread>
#include <mutex>

template <typename Key, typename Value>
class redisCache{

	private:
		// Store values in cache and keep track 
		std::unordered_map<Key, std::pair<Value, typename std::list<Key>::iterator>>cacheMap;
		std::list<Key> cache;
		unsigned int size;

		// Store expiration of keys with minHeap sorted by time to expire 
		std::priority_queue<std::pair<time_t, Key>> expirationHeap; 

		void removeExpiredKeys();
	
		void expirationThread();

		std::mutex mx;

		bool running = true;
	public:
		redisCache(const unsigned int &capacity);
		
		~redisCache();
		void put(const Key &key, const Value &value);

		void expire(time_t secondsToExpire, const Key &key);

		typename std::optional<Value> get(const Key& key);

};


#endif

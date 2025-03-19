#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <utility>
#include <optional>


template <typename Key, typename Value>
class lruCache{

	private:
		std::unordered_map<Key, std::pair<Value, typename std::list<Key>::iterator>>cacheMap;
		std::list<Key> cache;
		unsigned int size;
	public:
		lruCache(const unsigned int &capacity);

		void put(const Key &key, const Value &value);

		typename std::optional<Value> get(const Key& key);

};


#endif

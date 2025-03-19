#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <utility>


template <typename Key, typename Value>
class lruCache{

	private:
		typedef std::unordered_map<Key, std::pair<Value, typename std::list<Key>::iterator>>cacheMap;
		std::list<Key> cache;
		int size;
	public:
		lruCache();

		void put(const Key &key, const Value &value);

		Value get(const Key& value);

};


#endif

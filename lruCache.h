#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <utility>


template <typename T>
class lruCache{

	private:
		std::unordered_map<T,std::pair<T, std::list<T>::iterator>> cacheMap;
		std::list<T> cache;
		int size;
	public:
		lruCache();

		void put(const T &key, const T &value);

		T get(const T& value);

}


#endif

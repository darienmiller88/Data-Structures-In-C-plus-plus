#pragma once
#include <vector>
#include <list>
#include <string>
#include <initializer_list>
#include <iostream>
#include <numeric>

//this fancy looking hack is a convient way of re defining very long, boiler platey code into whatever the hell
//I would like it to be :D
//I am using the key word "using" to redefine "list<Entry>::iterator" to mean "listIter" and  "std::pair<std::string, int>"
//so this way, declartions can be more concise.
using Entry = std::pair<std::string, int>;
using listIter = std::list<Entry>::iterator;


/**
*
*@Author Darien Miller 
*
* Here is the map class that will be used to implement the STL map using a hash table as opposed to a binary search
* tree. And WOW, Holy shit this was fun!
*
*/

class Map{
	public:
		Map();
		Map(const std::initializer_list<Entry> &list);
		void insert(const std::string &key, int value);
		bool containsKey(const std::string &key);
		bool containsValue(int value);
		void erase(const std::string &key);
		int getValueOf(const std::string &key);
		int &operator [] (const std::string &key);
		int size() const;
		bool empty() const ;
		friend std::ostream &operator << (std::ostream &os, const Map &m);
	private:
		int numElements;
		int hashFunction(const std::string &key);
		listIter search(const std::string &key, int index);
		std::vector< std::list<Entry> > table;
};


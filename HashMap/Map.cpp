#include "Map.h"

Map::Map() : table(20), numElements(0){
}

Map::Map(const std::initializer_list<Entry>& list) : table(20), numElements(0) {
	for (auto &elem : list)
		insert(elem.first, elem.second);
}

void Map::insert(const std::string &key, int value){
	int index = hashFunction(key);
	auto it = search(key, index);
	
	//if the key passed to this function as a parameter was NOT found in the map, insert this key-value pair 
	//into the specified index in the vector.
	if (it == table[index].end()) {
		table[index].push_back(Entry(key, value));
		numElements++;
	}
	
	//if the key passed to this function WAS found....
	else
		it->second = value;//change the value of second to "value" 
}

bool Map::containsKey(const std::string & key){
	//find the index of the list where we will insert to.
	int index = hashFunction(key);
	
	//if the iterator from the findKey function is equal to .end(), return false if the value was not found, and true
	//otherwise.
	return search(key, index) != table[index].end();
}

bool Map::containsValue(int value){
	for (auto &bucket : table)
		for (auto &elem : bucket)
			if (elem.second == value)
				return true;
	return false;
}

void Map::erase(const std::string &key){
	int index = hashFunction(key);
	auto it = search(key, index);
	
	if (it != table[index].end())
		table[index].erase(it);
	else
		std::cout << "Key \"" << key << "\" is not in the map!\n";
}

int Map::getValueOf(const std::string &key){
	return search(key, hashFunction(key))->second;
}

int &Map::operator[](const std::string &key){
	int index = hashFunction(key);
	auto it = search(key, index);

	if (it == table[index].end()) {
		table[index].push_back(Entry(key, 0));
		return table[index].back().second;
	}
	else 
		return it->second;	
}

int Map::size() const {
	return table.size();
}

bool Map::empty() const {
	return numElements == 0;
}

int Map::hashFunction(const std::string & key){
	return std::accumulate(key.begin(), key.end(), 0) % table.size();
}

listIter Map::search(const std::string &key, int index){
	for (auto it = table[index].begin(); it != table[index].end(); it++) 
		if (it->first == key)
			return it;
	return table[index].end();
}

std::ostream & operator<<(std::ostream &os, const Map & m){
	int bucketNumber = 0;

	for (auto &bucket : m.table) {
		os << "[" << bucketNumber << "]: ";
		for (auto &elem : bucket)
			os << elem.first << " " << elem.second << " -> ";
		os << "\n\n";
		bucketNumber++;
	}

	return os;
}

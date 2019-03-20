#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <initializer_list>

using Entry = std::pair<std::string, int>;

//Map class that will map strings to int for simplicity.
class Map{
	
	struct Node {
		std::string key;
		int value;
		std::unique_ptr<Node> left;
		std::unique_ptr<Node> right;
	};

	public:
		Map();
		Map(const std::initializer_list< Entry > list);
		~Map();
		int size() const;
		int count(const std::string &key) const;
		bool empty() const;
		void insert(const Entry &entry);
		int &operator [] (const std::string &key);
		friend std::ostream &operator << (std::ostream &os, const Map &m);

		class iterator {
			public:
				iterator(Node *data = nullptr) : data(data){

				}

				iterator(const iterator &rhs) : data(rhs.data) {

				}

				iterator &operator =(const iterator &rhs) {

				}

				iterator &operator++() {

				}

				iterator &operator++(int) {

				}

				Node &operator *() {
					return *data;
				}



			
			private:
				Node *data;
		};

		iterator begin() {
			return iterator(head.get());
		}

		iterator end() {
			return iterator();
		}*/
	private:
		Node *newNode;//this pointer will keep track of where each new node is.
		void insertIntoTree(std::unique_ptr<Node> &head, const Entry &entry);
		static void printInOrder(std::ostream &os, Node *root);
		bool search(Node *root, const std::string &key) const;
		std::unique_ptr<Node> head;
		int len;

};


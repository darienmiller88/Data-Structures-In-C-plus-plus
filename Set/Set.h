#pragma once
#include <iostream>

using std::ostream;
using std::cout;
using std::endl;

class Set{
	public:
		Set();
		Set(int *begin, int *end);
		~Set();
		void insert(const int &key);
		void erase(const int &key);
		bool find(const int &key);
		int length() const;
		friend ostream &operator<<(ostream &os, Set &set);
	private:
		struct Node {
			Node() {}
			Node(const int &value) : key(value){}
			int key;
			Node *leftNode;
			Node *RightNode;
		};
		static void printPreOrder(Node *rootPtr);
		static void deleteNodes(Node *rootPtr);
		static bool search(Node *rootPtr, int key);
		static void insertNodes(Node *&rootPtr, int key);
		Node *rootPtr;

		int size;
};


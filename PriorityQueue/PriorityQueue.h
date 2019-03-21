#pragma once
#include <vector>
#include <iostream>

using std::swap;
using std::cout;
using std::vector;
using std::ostream;

class PriorityQueue{
	public:
		PriorityQueue();
		PriorityQueue(int *begin, int *end);
		int &operator[](const int & val);
		void push(const int &val);
		void pop();
		int &top();
		int size() const;
		bool empty();
		friend ostream &operator<<(ostream &os, PriorityQueue &que);
	private:
		static void exceptionSafety();
		static int findMaxIndex(const int &leftChild, const int &rightChild, const int &root, vector<int> &data);
		vector<int> data;
};
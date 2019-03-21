#ifndef STACK_H
#define STACK_H

#include <vector>

using std::vector;

template <class var>
class Stack{
	public:
		Stack();
		Stack(const int &initSize, const var &initVal = var());
		Stack(var *begin, var *end);
		void push(const var &val);
		void pop();
		var &top();
		int size() const;
		bool empty();
		void swap(Stack &otherStack);
	private:
		vector<var> data;
};

#include "Stack.cpp"

#endif
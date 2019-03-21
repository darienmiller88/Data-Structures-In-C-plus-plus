#include "Stack.h"

template<class var>
Stack<var>::Stack(){
}

template<class var>
Stack<var>::Stack(const int &Size, const var &initVal) {
	for (int i = 0; i < Size; i++) 
		data.push_back(initVal);
}

template<class var>
Stack<var>::Stack(var *begin, var *end) {
	while (begin != end) {
		data.push_back(*begin);
		begin++;
	}
}

template<class var>
void Stack<var>::push(const var &val) {
	data.push_back(val);
}

template<class var>
void Stack<var>::pop() {
	if(!empty())
		data.pop_back();
}

template<class var>
bool Stack<var>::empty() {
	return data.size() == 0;
}

template<class var>
int Stack<var>::size() const {
	return data.size();
}

template<class var>
var &Stack<var>::top() {
	return data.back();
}

template<class var>
void Stack<var>::swap(Stack &otherStack) {
	data.swap(otherStack.data);
}

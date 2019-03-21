#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
	Stack<int> s1;

	s1.push(3);
	s1.push(6);
	s1.push(8);

	s1.top() = 5;

	while (!s1.empty()) {
		cout << s1.top() << " ";
		s1.pop();
	}
	
	system("pause");
}

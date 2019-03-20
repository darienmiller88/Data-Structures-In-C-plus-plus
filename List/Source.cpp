#include <iostream>
#include "List.h"

using namespace std;

int main() {
	List l{3, 5, 1, 6, 7};

	l.push_front(56);
	l.push_front(45);
	l.push_back(41);

	cout << l << endl;


}
#include <iostream>
#include "Set.h"
using namespace std;

int main() {
	int arr[]{ 3, 4, 1, 6, 2, 10, 6, 3};
	Set set(arr, arr+8);

	set.insert(7);
	set.insert(9);
	set.insert(0);
	set.insert(-2);
	set.insert(7);
	set.insert(7);
	set.insert(7);
	cout << set << endl;

	if (set.find(7))
		cout << "7 was found\n";
	else
		cout << "7 was not found\n";
	
	cout << "Size: " << set.length() << endl;

	system("pause");
}
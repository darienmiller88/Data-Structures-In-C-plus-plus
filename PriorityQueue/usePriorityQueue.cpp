#include "PriorityQueue.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	int arr[]{ 2, 4, 1, 3, 8, 5, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	PriorityQueue que(arr, arr + n);
	PriorityQueue que2;
	srand(time(0));

	for (int i = 0; i < 10; i++) 
		que2.push(rand() % 100);

	while (!que2.empty()) {
		cout << que2 << endl << endl;
		que2.pop();
	}

	cout << "\nEnter to continue...\n";
	cin.get();
}
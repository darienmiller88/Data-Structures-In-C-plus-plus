#include <iostream>
#include <vector>
#include <array>
#include <chrono>
#include "Vector.h"
using namespace std;

int main() {
	Vector v{ 3, 4 ,6, 1, 7, 9 };
	Vector::iterator it;
	it = v.begin();

	while (it != v.end()) {
		cout << *it << endl;
		it++;
	}
}
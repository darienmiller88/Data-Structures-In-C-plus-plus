#include <iostream>
#include "Map.h"
using namespace std;

int main() {
	Map map{ {"Darien", 69}, {"Denise", 15}, {"Zira", 90}, {"Richard", 50} };

	map["Dalton"] = 45;
	map["Emily"] = 86;
	map.insert({ "Darien", 100 });
	map["Darien"] = 70;

	cout << map.count("Denise") << endl;


	cout << map << endl;
}
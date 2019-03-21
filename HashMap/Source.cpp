#include <iostream>
#include "Map.h"

using namespace std;

int main() {
	Map m{ {"Darien", 69}, {"Denise", 99}, {"Vulis", 0}, {"Stephanie", 89}, {"Andre", 23} };

	m.insert("Ari", 50);

	if (m.containsValue(69))
		cout << "69 is in the map\n";

	m.erase("Mars");
	//m.erase("Denise");

	cout << "The value for key Darien: " << m.getValueOf("Darien") << endl;

	m["Fredfred Burger"] = 78;
	m["Mom"] = 1964;
	m["Greg"] = 119;
	m["Sonic"] = 1991;
	m["Mario"] = 1983;

	cout << m << endl;
}
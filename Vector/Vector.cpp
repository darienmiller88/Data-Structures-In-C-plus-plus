#include "Vector.h"

Vector::Vector() : currentLen(0), allocatedLen(50), data(std::make_unique<int[]>(allocatedLen)){
	
}

Vector::Vector(const std::initializer_list<int> &list) : currentLen(0), allocatedLen(50), data(std::make_unique<int[]>(allocatedLen)) {
	for (auto &elem : list) 
		push_back(elem);
}

Vector::Vector(int initialSize, int initialValue) : currentLen(0), allocatedLen(50), data(std::make_unique<int[]>(allocatedLen)){
	if (initialSize >= allocatedLen)
		grow();
	for (int i = 0; i < initialSize; i++)
		push_back(initialValue);
}


Vector::Vector(const Vector &rhs) : currentLen(rhs.currentLen), allocatedLen (rhs.allocatedLen), data(std::make_unique<int[]>(allocatedLen)) {
	for (int i = 0; i < currentLen; i++)
		data[i] = rhs.data[i];
	std::cout << "copy constructor called!\n";

}

Vector::Vector(Vector &&rhs) : currentLen(rhs.currentLen), allocatedLen(rhs.allocatedLen), data(std::move(rhs.data)){
	std::cout << "move constructor called!\n";
}

Vector &Vector::operator=(const Vector &lhs){
	if (this != &lhs) {
		currentLen = lhs.currentLen;
		allocatedLen = lhs.allocatedLen;
		for (int i = 0; i < currentLen; i++)
			data[i] = lhs.data[i];
	}
	return *this;
}

Vector &Vector::operator = (Vector &&lhs){
	currentLen = lhs.currentLen;
	allocatedLen = lhs.allocatedLen;
	data = std::move(lhs.data);

	return *this;
}

Vector::~Vector()
{
}

void Vector::push_back(int val){
	if (currentLen == allocatedLen)
		grow();
	data[currentLen] = val;
	currentLen++;
}

void Vector::pop_back(){
	if(currentLen > 0)
		currentLen--;
}

int Vector::size() const{
	return currentLen;
}

int &Vector::at(int index) const{
	if (index >= currentLen || index < 0)
		throw std::out_of_range("Index out of bounds!") ;
	return data[index];
}

int &Vector::operator[](int index) const{
	return at(index);
}

void Vector::grow(){
	allocatedLen *= 2;
	auto newArr = std::make_unique<int[]>(allocatedLen);
	newArr.swap(data);
	data = std::move(newArr);	
}

std::ostream &operator<<(std::ostream &os, const Vector &v){
	os << "[";
	
	for (size_t i = 0; i < v.size(); i++){
		os << v[i] << ", ";
	}
	
	os << "]\n";

	return os;
}

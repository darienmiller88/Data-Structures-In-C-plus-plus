#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(){
}

PriorityQueue::PriorityQueue(int *begin, int *end){
	while (begin != end) {
		push(*begin);
		begin++;
	}
}

int &PriorityQueue::operator[](const int & val){
	if (val < 0 or val >= data.size()) {
		cout << "\n\nArrayOutOfBoundsException: " << val << "\n";
		exceptionSafety();
	}
	return data[val];
}

void PriorityQueue::push(const int &val) {
	data.push_back(val);
	int currentIndex = data.size() - 1;

	//while the value of the leaf node is greater than the value of the parent node and we are not at the root...
	while (data[currentIndex] > data[(currentIndex - 1) / 2]) {
		//swap them into their correct positions!
		swap(data[currentIndex], data[(currentIndex - 1) / 2]);
		currentIndex = (currentIndex - 1) / 2;//set the current index of the value we're pushing 
		//to be the index of its parent
	}
}

void PriorityQueue::pop() {
	int currentIndex = 0, leftChildIndex = (2 * currentIndex) + 1, rightChildIndex = (2 * currentIndex) + 2;
	int maxIndex;

	//if the client tries to call pop_back() on a empty queue, call function and exit program
	if (data.size() == 0) 
		exceptionSafety();
	
	//swap the root with the last element in the array
	swap(data[0], data.back());

	//remove the last element in the array
	data.pop_back();

	//finally, call the private static helper function to update the index of the largest value. i.e.
	//between the parent, and its children, which value is the largest? This function will return the 
	//index of the largest one, which will be stored in "maxIndex".
	maxIndex = findMaxIndex(leftChildIndex, rightChildIndex, currentIndex, data);

	//If the value of the new root is less than at least one of its children, enter the loop
	//data[currentIndex] < data[leftChildIndex] || data[currentIndex] < data[rightChildIndex]
	//leftChildIndex < data.size() and rightChildIndex < data.size()
	//and data[currentIndex] <= data[maxIndex]

	//while the greatest index is NOT the parent(meaning either the left or right child)...
	while (maxIndex != currentIndex){
		//swap the root with the bigger of its children (or only child! Some roots only have one child)
		swap(data[currentIndex], data[maxIndex]);

		//set the current to the max index
		currentIndex = maxIndex;

		//find the index of the left child
		leftChildIndex = (2 * currentIndex) + 1;
		
		//find the index of the right child
		rightChildIndex = (2 * currentIndex) + 2;

		//finally, call the max function again to update the new maximum index, and continue down the tree until
		//the maxIndex is the index of a parent, not that of any of its children, Or node without any children at all.
		 maxIndex = findMaxIndex(leftChildIndex, rightChildIndex, currentIndex, data);
	}
}

int PriorityQueue::size() const{
	return data.size();
}

bool PriorityQueue::empty() {
	return data.size() == 0;
}

void PriorityQueue::exceptionSafety(){ 
	cout << "\nEnter to continue...\n";
	std::cin.get();
	exit(1);
}

int PriorityQueue::findMaxIndex(const int &leftChild, const int &rightChild, const int &root, vector<int> &data){
	int maxIndex;

	//check to see if "leftChild" (index of the left child) is not out of bounds and the value at that index
	//is less than that of its parent. If true, the max index is now the index of the left child
	if (leftChild < data.size() and data[leftChild] > data[root]) 
		maxIndex = leftChild;

	//if the above statement is not true (parent is great then left child), then the max index is that of the parent
	else 
		maxIndex = root;
		
	//if the index of the right child is in bounds and the value at that index is greater than the value at maxIndex,
	//change the maxIndex to be the index of the riht child.
	if(rightChild < data.size() and data[rightChild] > data[maxIndex])
		maxIndex = rightChild;

	return maxIndex;
}

int &PriorityQueue::top() {
	if (empty())
		exceptionSafety();
	return data[0];
}

ostream & operator<<(ostream & os, PriorityQueue & que){
	for (int i = 0; i < que.data.size(); i++)
		os << que.data[i] << " ";
	return os;
}
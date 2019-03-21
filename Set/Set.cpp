#include "Set.h"

Set::Set() : rootPtr(nullptr), size(0){
}

Set::Set(int *begin, int *end) : rootPtr(nullptr), size(0) {
	Node *rootNode = new Node(*begin);//create a root node that will initialize our tree
	rootPtr = rootNode;//set the root pointer to point to this node
	rootPtr->leftNode = rootPtr->RightNode = nullptr;//set the node's left and right pointers to null
	size++, begin++;

	while (begin != end) {
		insert(*begin);
		begin++;
	}
}

Set::~Set(){
	deleteNodes(rootPtr);
}

void Set::insert(const int &key){
	if (!find(key)){
		insertNodes(rootPtr, key);
		size++;
	}
}

void Set::insertNodes(Node *&rootPtr, int key) {
	if (rootPtr == nullptr) {
		rootPtr = new Node(key);
		rootPtr->leftNode = rootPtr->RightNode = nullptr;
		return;
	}
	if (key > rootPtr->key) 
		insertNodes(rootPtr->RightNode, key);
	else 
		insertNodes(rootPtr->leftNode, key);
}

/*
void Set::erase(const int &key){
	Node *nodeToErase = search(rootPtr, key);
	Node *parentNode = rootPtr;

	while (parentNode->leftNode != nodeToErase and parentNode->RightNode != nodeToErase) {
		if (key > parentNode->key)
			parentNode = parentNode->RightNode;
		else
			parentNode = parentNode->leftNode;
	}

	if (nodeToErase == nullptr)//this case will account for either the empty, or if the value was not found
		cout << "Value was not found in Set.\n";
	//this case will account for when the node with the key is found, AND it has NO children (at the bottom of
	//the tree)
	else if (nodeToErase->leftNode == nullptr and nodeToErase->RightNode == nullptr) {
		(parentNode->leftNode == nodeToErase) ? parentNode->leftNode = nullptr : parentNode->RightNode = nullptr;		
		delete nodeToErase;
	}
	//this case will account for a node with only one child, the right child in particular
	else if (nodeToErase->leftNode == nullptr and nodeToErase->RightNode != nullptr) {
		if(parentNode->leftNode == nodeToErase)
			parentNode->leftNode = nodeToErase->RightNode;
		else
			parentNode->RightNode = nodeToErase->RightNode;
		delete nodeToErase;
	}
	//this case will account for a node with only one child, the left child in particular
	else if (nodeToErase->leftNode != nullptr and nodeToErase->RightNode == nullptr) {
		if (parentNode->leftNode == nodeToErase)
			parentNode->leftNode = nodeToErase->leftNode;
		else
			parentNode->RightNode = nodeToErase->leftNode;
		delete nodeToErase;
	}
	//finally, account for the case where the node we are erasing has two children
	else {
		if (parentNode->leftNode == nodeToErase) {

		}
		else {
			parentNode->RightNode = nodeToErase->leftNode;
		}
	}
	
}*/

bool Set::find(const int &value){
	if (search(rootPtr, value))
		return true;
	return false;
}

int Set::length() const{
	return size;
}

void Set::printPreOrder(Node *rootPtr){
	if (rootPtr == nullptr)
		return;
	printPreOrder(rootPtr->leftNode);
	cout << rootPtr->key << " ";
	printPreOrder(rootPtr->RightNode);
}

void Set::deleteNodes(Node *rootPtr){
	if (rootPtr == nullptr)
		return;
	deleteNodes(rootPtr->leftNode);
	deleteNodes(rootPtr->RightNode);
	delete rootPtr;
}

bool Set::search(Node *rootPtr, int key){
	if (rootPtr == nullptr)
		return false;
	if (rootPtr->key == key)
		return true;
	if (key > rootPtr->key)
		search(rootPtr->RightNode, key);
	else
		search(rootPtr->leftNode, key);
}

ostream &operator<<(ostream &os, Set &set){
	set.printPreOrder(set.rootPtr);
	return os;
}
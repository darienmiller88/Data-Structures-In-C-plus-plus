#include "List.h"

List::List() : len(0), head(nullptr), tail(nullptr){
}

List::List(const std::initializer_list<int> &list) : len(0), head(nullptr), tail(nullptr) {
	for (auto &elem : list)
		push_back(elem);
}

List::~List() {
}

void List::push_back(int val){
	if (tail == nullptr) {
		head = std::make_unique<Node>(val);
		tail = head.get();
		head->next = nullptr;
		head->previous = nullptr;
	}
	else {
		tail->next = std::make_unique<Node>(val);
		(tail->next)->previous = tail;
		tail = tail->next.get();
		tail->next = nullptr;
	}
	len++;
}

void List::push_front(int val){
	if (head == nullptr) {
		head = std::make_unique<Node>(val);
		tail = head.get();
		head->next = nullptr;
	}else{
		auto newNode = std::make_unique<Node>(val);
		head->previous = newNode.get();
		newNode->next = std::move(head);
		head = std::move(newNode);
	}
	head->previous = nullptr;
	len++;
}

void List::pop_back(){
	if (tail == nullptr) {
		std::cout << "Trying to call pop_back() on empty list\n";
		return;
	}

	if(len == 1){
		head.reset(nullptr);
		tail = head.get();
		len--;
	}else{
		tail = tail->previous;
		tail->next.reset(nullptr);
		len--;
	}
}

void List::pop_front(){
	if(head == nullptr){
		std::cout << "Trying to call pop_front() on empty list\n";
		return;
	}
	
	head = std::move(head->next);
	(len == 1) ? tail = nullptr : head->previous = nullptr;
	len--;
}

int &List::back() const{
	if (tail == nullptr)
		throw std::exception("Trying to call back() on empty list\n");
	return tail->data;
}

int &List::front() const{
	if (head == nullptr)
		throw std::exception("Trying to call front() on empty list\n");
	return head->data;
}

void List::printNodes() const{
	Node *temp = head.get();

	std::cout << "[";
	while (temp != nullptr) {
		std::cout << temp->data << ", ";
		temp = temp->next.get();
	}
	std::cout << "]";
}

int List::size() const{
	return len;
}

bool List::empty() const{
	return len == 0;
}

std::ostream &operator<<(std::ostream & os, const List & l){
	l.printNodes();
	
	return os;
}

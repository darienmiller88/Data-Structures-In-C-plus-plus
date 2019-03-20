#pragma once
#include <iostream>
#include <memory>
#include <initializer_list>
#include <exception>

class List{
	public:
		List();
		List(const std::initializer_list<int> &list);
		~List();
		int size() const;
		bool empty() const;
		void push_back(int val);
		void push_front(int val);
		void pop_back();
		void pop_front();
		int &back() const;
		int &front() const;
		friend std::ostream &operator << (std::ostream &os, const List &l);
		
	private:
		void printNodes() const;
		static void exception(bool condition);
		struct Node {
			Node(int data) : data(data) {}
			std::unique_ptr<Node> next;
			Node *previous;
			int data;
		};
		int len;
		std::unique_ptr<Node> head;
		Node *tail;
};


#pragma once
#include <memory>
#include <initializer_list>
#include <iostream>
#include <exception>

class Vector{
	public:
		Vector();
		Vector(const std::initializer_list<int> &list);
		Vector(int initialSize, int initialValue = 0);
		Vector(const Vector &rhs);
		Vector(Vector &&rhs);//copy constructor for rvalues.
		Vector &operator = (const Vector &rhs);
		Vector &operator = (Vector &&rhs);//assignment operator for right values
		~Vector();
		void push_back(int val);
		void pop_back();
		int size() const;
		int &at(int index) const;
		int &operator [] (int index) const;
		friend std::ostream &operator << (std::ostream &os, const Vector &v);

		class iterator {
			public:
				iterator(int *data = nullptr) : start(data) {
					
				}

				iterator(const iterator &iter) : start(iter.start){
					
				}

				iterator operator++() {
					start++;
					return *this;
				}
				
				iterator operator++(int) {
					return operator++();
				}

				iterator &operator = (const iterator &rhs) {
					if (this != &rhs) {
						start = rhs.start;
					}
					return *this;
				}

				bool operator ==(const iterator &rhs) {
					return this->start == rhs.start;
				}

				bool operator != (const iterator &rhs) {
					return !operator==(rhs);
				}

				int &operator *() { 
					return *start;
				}

				int *operator ->() {
					return start;
				}

			private:
				int *start;
		};

		iterator begin() const {
			return iterator(data.get());
		}

		iterator end() const {
			return iterator(data.get() + currentLen);
		}

	private:
		void grow();	
		int currentLen;
		int allocatedLen;
		std::unique_ptr<int[]> data;
};


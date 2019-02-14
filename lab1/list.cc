#include <iostream>
#include "list.h"


	List::List() {
		first = nullptr;
	}

	List::~List() {

		Node *tmp = first;
		while(tmp->next != nullptr) {
			Node *next = tmp->next;
			delete tmp;
			tmp = next;
		}
		delete tmp; //comment out this line to introduce memory leak...
	}

	bool List::exists(int d) const {
		Node *current = first;
		while(current != nullptr) {
		//while(true) {
			if(current->value == d) {
				return true;
			} else {
				current = current->next;
			}
		} 
		return false;
	}

	//use iterator instead
	int List::size() const {
		int size = 0;
		Node *current = first;
		while(current != nullptr) {
			current = current->next;
			size++;
		}
		return size;
	}

	bool List::empty() const {
		return first == nullptr; 
	}

	void List::insertFirst(int d) {
		first = new Node(d, first);
		
	}

	void List::remove(int d, DeleteFlag df) {
		Node *pre = nullptr;
		Node *current = first;

		while(current->next != nullptr) {
		//while(true) {	

			bool deleteNode = false; //had several if statements before, using switch case seemed way cleaner;
									 //if the flag is changed, jump out of and delete node, continues afterwards
			
			switch(df) {
				case DeleteFlag::LESS:
					if(current->value < d) {
						deleteNode = true; 
					}
					break;

				case DeleteFlag::EQUAL:
					if(current->value == d) {
						deleteNode = true; 
					}
					break;

				case DeleteFlag::GREATER:
					if(current->value > d) {
						deleteNode = true; 
					}
					break;
			}
			
			if(deleteNode) {
				Node *next = current->next;

				if(current == first) {
					first = next;
					pre = nullptr;
				}

				else {
					pre->next = next;
				}

				delete current;
				current = next;
			}

			pre = current;
			current = current->next;
		}
	}

	void List::print() const {
		Node* current = first;
		
		while(current != nullptr) {
			std::cout << current->value << ", ";
			current = current->next;
		}	
	}



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
	}

	bool List::exists(int d) const {
		Node *current = first;
		while(current != nullptr) {
			if(current->value == d) {
				return true;
			} else {
				current = current->next;
			}
		}
		return false;
	}

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
		return first == nullptr; //snabbast?
		//return size() == 0; kan man skriva så?
		// int n = size();
		// if(n == 0) {
		// 	return true;
		// } else {
		// 	return false;
		// }
	}

	void List::insertFirst(int d) {
		first = new Node(d, first);
		// Node* tmp = new Node(d, first);
		// first = tmp;
		// delete tmp;
	}

	//deleting actual node and not just the pointer?
	void List::remove(int d, DeleteFlag df) {
		Node *pre = nullptr;
		Node *current = first;

		while(current->next != nullptr) {
			
			bool deleteNode = false;
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
			std::cout << current->value << ", "; //infinite loop
			current = current->next;
		}
	
	}


	// a list node 
	struct Node {
		int value; // the node value
		Node* next; // pointer to the next node, nullptr in the last node
		Node(int v, Node* n) : value(v), next(n) {}
	};
	Node* first; // pointer to the first node




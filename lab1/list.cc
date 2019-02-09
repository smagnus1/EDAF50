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
				pre = current;
				current = current->next;

				switch(df) {
					case DeleteFlag::LESS:
						if(current->value < d) {
							pre->next = current->next;
							delete current;	
						}

					case DeleteFlag::EQUAL:
						if(current->value == d) {
							pre->next = current->next;
							delete current;					
						}

					case DeleteFlag::GREATER:
						if(current->value > d) {
							pre->next = current->next;
							delete current;	
						}
				}
				// if(df == DeleteFlag::EQUAL && current->value == d) {
				// 		pre->next = current->next;
				// 		delete current;
				// } else if(df == DeleteFlag::LESS && current->value < d){
				// 		pre->next = current->next;
				// 		delete current;
				// } else if(df == DeleteFlag::GREATER && current->value > d) {
				// 		pre->next = current->next;
				// 		delete current;
				// }
				current = pre->next;
			}
			delete current; 
		}

		void List::print() const {
			Node* current = first;
			
			while(current != nullptr) {
				std::cout << current->value + ", " << std::endl; //infinite loop
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





/*
class List {

	public:
		List::List() {
			first = NULL;
		}


		List::~List() {
			while(first->next != NULL) {
				Node* tmp = first;
				first = tmp->next;
				delete tmp;
				tmp = NULL;
			}
		}

		bool List::exists(int d) const {
			Node* current = first;
			while(current != NULL) {
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
			Node* current = first;
			while(current != NULL) {
				size++;
				current = current->next;
			}
			return size;
		}

		bool List::empty() const {
			//return size() == 0; kan man skriva så?
			int n = size();
			if(n == 0) {
				return true;
			} else {
				return false;
			}
		}

		void List::insertFirst(int d) {
			Node* tmp = Node(d, first);
			first = tmp;
			delete tmp;
			tmp = NULL;
		}

		void List::remove(int d, DeleteFlag df) {
			Node* current = first;
			Node* pre = null;
			while(current->next != NULL) {
				pre = current;
				current = current->next;
				if(df == EQUAL && current->value == d) {
					pre->next = current->next;
					delete current;
				} else if(df == LESS && current->value < d){
					pre->next = current->next;
					delete current;
				} else if(df == GREATER && current->value > d) {
					pre->next = current->next;
					delete current;
				}
				current = pre->next;
			}
			delete current;
		}

		void List::print() const {
			Node* current = first;
			while(current != NULL) {
				std::cout << current.value + ", " << std::endl;
			}
			delete current;
		}

	private:
		// a list node 
		struct Node {
			int value; // the node value
			Node* next; // pointer to the next node, nullptr in the last node
			Node(int v, Node* n) : value(v), next(n) {}
		};
		Node* first; // pointer to the first node
};


*/
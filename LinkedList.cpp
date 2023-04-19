#include <iostream>
#include <algorithm>//included for the count() function used in the function fromVector
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr) {} //constructor

LinkedList::~LinkedList() //destructor
{
	Node* current = head;
	while (current)
	{
		Node* temp = current->next;
		delete current;
		current = temp;
	}
}

void LinkedList::add(int v, int o) { //adds a node to the list
	Node* newNode = new Node;
	newNode->value = v;
	newNode->occurences = o;
	newNode->next = nullptr;

	if (!head)
	{
		head = newNode;
	}
	else {
		Node* current = head;

		while (current->next)
		{
			current = current->next;
		}
		current->next = newNode;
	}
}

void LinkedList::remove(int v) { //removes a node given a its value
	if (!head)
		return;

	if (head->value == v) {
		Node* temp = head;
		head = head->next;
		delete temp;
		return;
	}

	Node* current = head;
	while(current->next && current->next->value != v) {
		current = current->next;
	}

	if (current->next) {
		Node* temp = current->next;
		current->next = current->next->next;
		delete temp;
	}

}

void LinkedList::print() const { //prints the nodes
	Node* current = head;
	cout << "The modified linked list is: "<<endl;
	while (current) {
		cout << current->value<< " occurs "<<current->occurences<<" times ";
		current = current->next;
		cout << endl;
	}
	cout << endl;
}



int LinkedList::sum() {
	int sum = 0;
	Node* current = head;
	while (current) {
		sum += current->value*current->occurences; //adds the value of the node multiplied by the number of times it is repeated to the total
		current = current->next;
	}
	return sum;
}

LinkedList LinkedList::fromVector(const std::vector<int>& v) {
	LinkedList list;

	for (int i = 0; i < v.size(); ++i) {
		int value = v[i];

		// Check if the value has not been added to the list already
		bool alreadyAdded = false;
		Node* current = list.head;
		while (current) {
			if (current->value == value) {
				alreadyAdded = true;
				break;
			}
			current = current->next;
		}

		if (!alreadyAdded) { //skip if the value is already in the vector
			int o = count(v.begin(), v.end(), value);
			                                          //counts the value's repetitions in the vector from v.begin to v.end
			list.add(value, o);                       // and stores it in the variable o
		}
	}

	return list;
}
 





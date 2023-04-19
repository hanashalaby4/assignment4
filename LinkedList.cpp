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
	while (current) {
		cout << current->value << " (" << current->occurences << ") -> ";
		current = current->next;
	}
	cout << "empty list" << endl;
}

int LinkedList::sum() {
	int sum = 0;
	Node* current = head;
	while (current) {
		sum += current->value; //adds the value of the node multiplied by the number of times it is repeated to the total
		current = current->next;
	}
	return sum;
}

LinkedList LinkedList::fromVector(const std::vector<int>& v) { //static so the function can be used without
	LinkedList list;                                      //having objects of the class LinkedList, given the function recieves a vector
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) { //iteration through vector
		int value = *it;
		int o = count(v.begin(), v.end(), value); //counts the value's repetitions in the vector from v.begin to v.end
												  // and stores it in the variable o
		list.add(value, o); //adds a node to the linked list with the value and its occurences
	}
	return list; //returns the list
}
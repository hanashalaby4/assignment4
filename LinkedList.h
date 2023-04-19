#ifndef LINKEDLIST
#define LINKEDLIST

#include <vector>

class LinkedList {

public:
	struct Node {
		int value, occurences;
		Node* next;
	};
	LinkedList(); //constructor
	~LinkedList(); //destructor

	//member functions

	void add(int v, int o); //function to add a node to the linked list

	void remove(int v); //function to remove a node from the linked list

	void print() const; //prints the nodes

	int sum(); //adds the values of the nodes in the linked list
	//traverses through the list and adds the value of the node multiplied by the number of times it is repeated

	static LinkedList fromVector(const std::vector<int>& v); //function returns the linked list displaying the number of occurences of each value

private:
	Node* head;

};

#endif //LINKEDLIST

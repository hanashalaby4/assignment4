//hana shalaby 900223042
//assignment 4
// program that takes from the user n integers and stores them a vector of int
//a function insertAfter that takes firstValue and secondValue. This function
//searches for each occurrence of firstValue in the vectorand insert the secondValue after
//it in the same vector.The firstand second values are taken from the user.


#include <iostream>
#include "LinkedList.h"
#include <vector>
using namespace std;
void insertAfter(vector<int>& v, int first, int second);


int main()
{
	int n;
	cout << "Please enter the number of integers: " << endl;
	cin >> n;

	vector <int> v(n);

	cout << "Please enter " << n << " integers: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int firstValue, secondValue;
	cout << "Enter the first value: " << endl;
	cin >> firstValue;
	cout << "Enter the second value: " << endl;
	cin >> secondValue;

	insertAfter(v, firstValue, secondValue);
	
	LinkedList list = LinkedList::fromVector(v);
	
	list.print();


	
	cout << "The sum of all the integers: " << list.sum() << endl;

	return 0;
}

void insertAfter(vector<int>& v, int first, int second)
{
	for (int i = 0; i < v.size(); i++) //iterates through the vector
	{
		if (v[i] == first) {
			v.insert(v.begin() + i + 1, second);
			i++;//inserts the second value specified directly after each occurence
			    //of the first value specified
		}
	
	}

}


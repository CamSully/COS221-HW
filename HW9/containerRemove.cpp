/* containerRemove.cpp 
* Author: Cameron Sullivan
* Date: 11-17-17
*
* This code contains a remove() function that is used to remove an element of any type from any sequential container (i.e. vector, deque, or list).
* The remove() function is tested with a vector of ints.
*/

#include <iostream>
#include <vector>
using namespace std;

// Prototypes: remove() and printContainer().
template<typename ElementType, typename ContainerType>
void remove(ContainerType&, const ElementType&);
template<typename ContainerType>
void printContainer(ContainerType&);



int main() {

	cout << "Cameron Sullivan - COS 221 - HW9 Output" << endl << endl;

	// Fill a vector with ints 1-6.
	vector<int> nums;
	for (int i = 1; i <= 6; i++) {
		nums.push_back(i);
	}

	cout << "Initial container: " << endl;
	printContainer(nums);

	cout << "Removing the value '4'..." << endl;
	remove(nums, 4);

	cout << "The container after the removal: " << endl;
	printContainer(nums);

	cout << "Attempting to remove '4' again..." << endl;
	remove(nums, 4);
	
	return 0;
}

// remove(): removes the first instance of 'value' from the container.
template<typename ElementType, typename ContainerType>
void remove(ContainerType& container, const ElementType& value) {
	
	// Create an iterator of the same type as the container.
	typename ContainerType::iterator it;
	// Iterate through each element of the container.
	for (it = container.begin(); it != container.end(); it++) {
		// If the value at the iterator's current index is the remove value...
		if ((*it) == value) {
			// Remove the value (erase() can take an iterator as an argument).
			container.erase(it);
			return;
		}
	}
	
	// If the value is not in the container, print a nice error message.
	cout << "Error: " << value << " was not found in the container!" << endl;

}

// printContainer(): iterate through the container and print each element.
template<typename ContainerType>
void printContainer(ContainerType& container) {
	typename ContainerType::iterator it;
	for (it = container.begin(); it != container.end(); it++) {
		cout << (*it) << " ";
	}
	cout << endl << endl;
}


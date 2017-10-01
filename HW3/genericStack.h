/* COS 221 - Cameron Sullivan - HW3
* Generic stack header: This header includes function implementation. 
* This is because generics are involved, so implementation must done in the header.
* This program simulates a typical computer stack: it allows the user to push data on and pop data off the stack, and also allows them to peek at the top element and check the size and emptiness of the stack.
* This program uses the  generic type to allow the user to create a stack of any variable type, and it uses a vector to allow for stack dynamic sizing.
*/

#include <vector>
using namespace std;

template<typename T>
class Stack 
{
public:
	// Public prototypes.
	Stack();
	bool empty() const;
	T peek() const;
	void push(T value);
	T pop();
	int getSize() const;

private:
	// Private variables.
	vector<T> elements;
	int size;
};

// Empty constructor
template<typename T>
Stack<T>::Stack() {
}

// empty() - Returns 1 if the stack is empty, 0 if the stack contains elements.
template<typename T>
bool Stack<T>::empty() const {
	return (elements.size() == 0);
}

// peek() - Returns the element on the top of the stack.
template<typename T>
T Stack<T>::peek() const {	
	return elements.at(elements.size() - 1);
}

// push() - Adds a new element on the top of the stack.
template<typename T>
void Stack<T>::push(T value) {
	elements.push_back(value);
}

// pop() - removes the top element from the stack (returns top element).
template<typename T>
T Stack<T>::pop() {
	T element = elements.at(elements.size() - 1);
 	elements.pop_back();
	return element;
}

// getSize() - returns the number of elements in the stack.
template<typename T>
int Stack<T>::getSize() const {
	return elements.size();
}

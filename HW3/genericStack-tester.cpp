/*
*
*/

#include <iostream>
#include <string>
#include <vector>
#include "genericStack.h"

using namespace std;

int main() {
	Stack<string> stringStack;
	cout << "Pushing 'Bird,' 'Cat,' and 'Dog' to the vector..." << endl;
	stringStack.push("Bird");
	stringStack.push("Cat");
	stringStack.push("Dog");
	
	cout << "Stack size: " << stringStack.getSize() << endl;
	cout << "Stack peek: " << stringStack.peek() << endl;
	cout << "Popping two elements..." << endl;
	stringStack.pop();
	stringStack.pop();
	cout << "Stack is empty? " << stringStack.empty() << endl;
	cout << "Stack peek: " << stringStack.peek() << endl;
	cout << "Popping an element..." << endl;
	stringStack.pop();
	cout << "Stack is empty? " << stringStack.empty() << endl;

	return 0;
}

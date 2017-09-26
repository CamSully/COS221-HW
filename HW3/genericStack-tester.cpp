/*
* COS 221 - Cameron Sullivan - HW3
* genericStack Tester: This program creates a stack object and shows the use of each stack function.
* Note that the class is implemented in the header file.
*/

#include <iostream>
#include <vector>
#include "genericStack.h"

using namespace std;

int main() {
	cout << "Cameron Sullivan - COS 221 - HW3 Output" << endl;

	// Create a Stack object and specify type string.
	Stack<string> stringStack;

	// Testing and output for the user- test all functions.
	cout << "Pushing 'Bird,' 'Cat,' and 'Dog' to the stack..." << endl;
	stringStack.push("Bird");
	stringStack.push("Cat");
	stringStack.push("Dog");
	
	cout << "Stack size: " << stringStack.getSize() << endl;
	cout << "Stack peek: " << stringStack.peek() << endl;
	cout << "Popping two elements..." << endl;
	stringStack.pop();
	stringStack.pop();
	cout << "Stack size: " << stringStack.getSize() << endl;
	cout << "Stack is empty? " << stringStack.empty() << endl;
	cout << "Stack peek: " << stringStack.peek() << endl;
	cout << "Popping an element..." << endl;
	stringStack.pop();	
	cout << "Stack size: " << stringStack.getSize() << endl;
	cout << "Stack is empty? " << stringStack.empty() << endl;

	return 0;
}

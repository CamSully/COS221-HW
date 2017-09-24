/*
*
*/

#include <iostream>
#include <string>
#include "genericStack.h"

using namespace std;

int main() {
	Stack<string> stringStack;
	stringStack.push("Bird");
	stringStack.push("Cat");
	stringStack.push("Dog");
	
	while(!stringStack.empty()) {
		cout << stringStack.pop() << " ";
	}
	cout << endl;

	return 0;
}

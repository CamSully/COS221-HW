/* COS 221 - Cameron Sullivan - HW3
*
*/

#include <vector>
using namespace std;

template<typename T>
class Stack 
{
public:
	Stack();
	bool empty() const;
	T peek() const;
	void push(T value);
	void pop();
	int getSize() const;

private:
	vector<T> elements;
	int size;
};

template<typename T>
Stack<T>::Stack() {
}

template<typename T>
bool Stack<T>::empty() const {
	return (elements.size() == 0);
}


template<typename T>
T Stack<T>::peek() const {
	return elements.at(elements.size() - 1);
}

template<typename T>
void Stack<T>::push(T value) {
	elements.push_back(value);
}


template<typename T>
void Stack<T>::pop() {
	elements.pop_back();
}


template<typename T>
int Stack<T>::getSize() const {
	return elements.size();
}

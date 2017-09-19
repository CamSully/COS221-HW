// COS 221 - Cameron Sullivan - HW2 - 9-19-17

#include <iostream>
using namespace std;

int minElement(int [], int);

int main(void) {
		
	int testNums[] = {1,2,4,5,10,100,2,-22};

	cout << minElement(testNums,8) << endl;

	return 0;
}

int minElement(int numList[], int size) {
	int min = *numList;
	
	cout << "Initial min: " << min << endl;	

	for (int i = 1; i < size; i++) {
		
		cout << "element " << i << ": " << *(numList + i) << endl;		

		if (*(numList + i) < min) {
			min = *(numList + i);
		}
		cout << "New min: " << min << endl;
	}
	return min;
}

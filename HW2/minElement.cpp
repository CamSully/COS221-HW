/* COS 221 - Cameron Sullivan - HW2 - 9-19-17
* Minimum Element: This program iterates through an array and finds the smallest element in the array.
* Pointers are used in the minElement function to ensure understanding of arrays and pointers.
*/ 

#include <iostream>
using namespace std;

// Prototype
int minElement(int [], int);

int main(void) {
	
	cout << "COS 221 - Cameron Sullivan - HW2 Output - 9-19-17" << endl;

	// Initialize the test array.	
	int testNums[] = {1,2,4,5,10,100,2,-22};

	// Calculate the size of the array so that it doesn't need to be manually changed for different arrays.
	int size  = sizeof(testNums) / sizeof(testNums[0]);

	// Run the minElement function to find the smallest value in the array.
	int minNum = minElement(testNums, size);
	cout << "The minimum value in the array is: " << minNum << endl;

	return 0;
}

// Smallest-element finding function.
int minElement(int numList[], int size) {
	// Start by assuming the min value is the first element in the array.
	int min = *numList;

	// Loop through all elements in the array.	
	for (int i = 1; i < size; i++) {	
		// If the value at the pointer to the ith element is less than the min, that value is the new min.
		if (*(numList + i) < min) {
			min = *(numList + i);
		}
	}
	return min;
}

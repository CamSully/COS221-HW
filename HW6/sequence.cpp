/* sequence.cpp 
* Author: Cameron Sullivan
* Date: 10-27-17
* 
* This code takes a series of space-separated numbers as input, and finds the longest sequence of consecutive numbers in that series.
* One major feature is that the input is initially taken as a string, and it is evaluated to ensure each character is an integer.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string initInput;	// String to hold initial input (before evaluation).
	int input;		// An int for each individual input to be added to the vector.
	vector<int> series;	// Vector of ints to hold the series.
	bool firstDigit = true; // A boolean to indicate whether the current input is the first character.

	cout << "Cameron Sullivan - COS 221 - HW6 output" << endl;
	cout << "Enter a series of numbers, terminated by 0:" << endl;

	// Allow the user to enter integers to fill the vector. Terminate when 0 is entered.
	while (input != 0) {
		cin >> initInput;

		// Ensure that the entered string is an int.
		// find_first_not_of returns the index of the first char that's not an int.
		// if string::npos is returned, the input is an int.
		if(initInput.find_first_not_of("0123456789") != string::npos) {
			cout << "Your input contains invalid characters. Terminating!" << endl;
			return 0;
		}

		// Now that we know the string is an int, convert it to an int.
			input = stoi(initInput);
		
		// If we are looking at the first digit of input and that digit is a 0, the series is empty.
		if (firstDigit && (input == 0)) {
			cout << "Empty series: terminating." << endl;
			return 0;
		}
		
		firstDigit = false;
		// Add the int to the vector of ints.
		series.push_back(input);

	}

	int count = 1;	  // Number of consecutive int.
	int maxIndex = 0; // Index of the first consecutive int.
	int maxCount = 1; // Maximum number of consecutive ints.
	int maxVal;	  // Value of the most consecutive int.

	// Iterate through the vector and find the longest sequence of the same number.
	for (int index = 0; index < series.size() - 1; index++) {
		
		if (series.at(index) == series.at(index + 1)) {
			count++;
			// If there is a new max number of consecutive digits, change the values.
			if (count > maxCount) {
			maxCount = count;
			maxIndex = index - (count - 2);
			}
		}
		else {
			// Reset count because the two elements are not the same.
			count = 1;
		}
	}
	maxVal = series.at(maxIndex);

	cout << "The longest same-number sequence starts at index " << (maxIndex + 1) << " with " << maxCount << " values of " << maxVal << "." << endl;

	return 0;
}


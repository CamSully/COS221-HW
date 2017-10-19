/* COS 221 - Cameron Sullivan - HW5
* stringPermutations: This program allows the user to enter a string, then prints all the permutations of that string.
* This program has two main parts:
* 1. A for-loop to swap/append chars. When s2 is more than 1 char long, the for-loop runs multiple times to reset string1 and string2, then append the next char of s2 onto s1.
* When s2 is 1 char long, the for-loop runs once and simply appends a char onto s1 (then s2 is empty, so the full s1 is printed).
* 2. A tail-recursive function call that calls the function with a more-simplified s1 and s2. This allows the function to progress deeper into the original s1 and s2, and swap/append those chars, eventually reaching the base case.
*/

#include <iostream>
#include <string>
using namespace std;

void displayPermutation(const string&, const string&);
void displayPermutation(const string&);

int main() {

	cout << "COS 221 - Cameron Sullivan - HW5" << endl << endl;
	string userString;

	// Prompt the user to enter a string.
	cout << "Enter a string to be permuted: ";
	cin >> userString;

	// Display the permutations of the user's string.
	displayPermutation(userString);

	return 0;
}


// Worker function: this function does the actual work on the strings and prints all the permutaions.
void displayPermutation(const string& s1, const string& s2) {

	// If the permutation is ready (all chars in s1), print the permutation (s1).
	if (s2.empty()) {
		cout << s1 << endl;
	}

	// If the permutation is NOT ready, swap/append chars between string1 and string2 to get it closer to a permutation.
	else {
		// Iterate through based on the size of s2.
		for (int i = 0; i < s2.size(); i++) {
			// Initialize strings 1 & 2. These non-const strings are needed because I can't change the argument variables.
			// These strings MUST be given a value inside the for-loop, because they need to be reset after every iteration.
			string string1 = s1;
			string string2 = s2;

			// Append the ith char of string2 onto string1.
			string1.append(1, string2.at(i));
			// Remove the ith char of string2.
			string2.erase(i, 1);

			// Recursively call the function with a new s1 and s2.
			displayPermutation(string1, string2);

		}
	}
}

// User function: this function is called by the user. It only exists to simplify the user's call (it only requires a single argument).
void displayPermutation(const string& s) {
	// Call the real displayPermutation function with an empty s1 and a full s2.
	displayPermutation("",s);
}

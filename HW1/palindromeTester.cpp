/*
* Cameron Sullivan - COS 221 - HW1 - 9-13-17
* Palindrome Tester: This program takes string input and evaluates the string.
* It determines if the string is a palindrome, and prints whether the string is a palindrome or not.
*/

#include <string>
#include <iostream>

using namespace std;

// Function prototype
bool isPalindrome(const string&);

int main() {
	
	// Prompt for input and accept it into testString.
	string testString;
	cout << "Enter a string to be palindrome tested: ";
	getline(cin, testString);

	// Run the palindrome tester with the test string.
	isPalindrome(testString);

	return 0;
}

// Palindrome-testing function.
bool isPalindrome(const string& s) {
 	
	// Get the index of the last character of the string.
	int high = s.length() - 1;

	// Loop until the low and high indices reach the middle character (odd) or go past each other (even).
	for (int low = 0; low < high; low++, high--) {
		// If the two characters are not the same, the string is not a palindrome.
		if (tolower(s[low]) != tolower(s[high])) {
			cout << "'" << s << "' is not a palindrome." << endl;
			return 0;
		}
	}
	
	// If all beginning and ending characters are the same, the string is a palindrome.
	cout << "'" << s << "' is a palindrome." << endl;
	return 1;
}

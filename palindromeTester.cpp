/*
* Cameron Sullivan - COS 221 - HW1
* Palindrome Tester: This program takes string input and evaluates the strings.
* It will determine if the string is a palindrome, and print its findings.
*/

#include <string>
#include <iostream>
#include <algorithm>     // For string transformation.

using namespace std;

bool isPalindrome(const string&);

int main() {
	string test1 = "Able was I ere I saw Elba";
	string test2 = "Boo hoo hoo";
	string test3 = "dad";
	string test4 = "rage";
	string test5 = "EPEPe";

	isPalindrome(test1);
	isPalindrome(test2);

	isPalindrome(test3);
	isPalindrome(test4);
	isPalindrome(test5);

	return 0;
}

bool isPalindrome(const string& s) {
	string tempString;
	tempString.assign(s);
	// CITE
	std::transform(tempString.begin(), tempString.end(), tempString.begin(), ::tolower);
 	
	int high = tempString.length() - 1;

	for (int low = 0; low < high; low++, high--) {
		
		if (tempString.at(low) != tempString.at(high)) {
			cout << "'" << s << "' is not a palindrome." << endl;
			return 0;
		}
	}

	cout << "'" << s << "' is a palindrome." << endl;

	return 1;
}

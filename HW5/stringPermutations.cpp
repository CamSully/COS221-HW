/* COS 221 - Cameron Sullivan - HW5
* 
*/

#include <iostream>
#include <string>
using namespace std;

void displayPermutation(const string&, const string&);
void displayPermutation(const string&);



int main() {

	displayPermutation("abc");

	return 0;
}



void displayPermutation(const string& s1, const string& s2) {
	
	
	for (int i = 0; i < s2.size(); i++) {
		
		// Define the strings inside the for-loop to reset them each iteration.
		string string1 = s1;
		string string2 = s2;
		
		if (string2.empty()) {
			cout << string1 << endl;
		}

		// Append on the "set" character.
		string1.append(1, string2.at(i));
		string2.erase(i, 1);
//		cout << "Iteration: " << i << " string1: " << string1 << " string2: " << string2 << endl;

			if (string2.empty()) {
				cout << string1 << endl;
			}
			
			else {
				// Send the next char.
				string1.append(1, string2.at(0));
				string2.erase(0, 1);
//				cout << "Iteration: " << i << " string1: " << string1 << " string2: " << string2 << endl;
				displayPermutation(string1, string2);
				
				// Append the last char of string1 onto string2.
				if (string2.empty()) {
					cout << string1 << endl;
					string tempString = string1;
					string1.at(string1.size() - 1) = tempString.at(tempString.size() - 2);
					string1.at(string1.size() - 2) = tempString.at(tempString.size() - 1);
					displayPermutation(string1, string2);
				}
				
				else {
					// Swap chars.
					string tempString = string1;
					string1.at(string1.size() - 1) = string2.at(0);
					string2.at(0) = tempString.at(tempString.size() - 1);
					displayPermutation(string1, string2);
				}
			}
	}

}

void displayPermutation(const string& s) {
	displayPermutation("",s);
}

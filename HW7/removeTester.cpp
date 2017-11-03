/* removeTester.cpp 
* Author: Cameron Sullivan
* Date: 11-1-17
* 
* This code tests the functionality of the LinkedList header. 
* A sentence is initialized, then that sentence is parsed into individual strings, which are loaded into a LinkedList object.
* Once the LinkedList is loaded with strings, the remove function is tested by removing all instances of "of."
*/

#include <iostream>
#include "LinkedList.h"
using namespace std;

// Prototypes.
void parseString(string, LinkedList<string>&);
void printList(LinkedList<string>);


int main() {

	// Create a LinkedList object of type string for the test sentence.
	LinkedList<string> list;
	
	cout << "Cameron Sullivan - COS 221 - HW7 Output" << endl << endl;
	cout << "Original linked list sentence: " << endl;
	
	const string sentence = "DURING the whole of a dull, dark, and soundless day in the autumn of the year, when the clouds hung oppressively low in the heavens, I had been passing alone, on horseback, through a singularly dreary tract of country; and at length found myself, as the shades of the evening drew on, within view of the melancholy House of Usher.";

	// Parse the string to remove punctuation and load words into the list.
	parseString(sentence, list);	
	printList(list);
	cout << endl;

	// Remove all instances of "of" from the list.
	cout << "Removing all instances of 'of' from the sentence..." << endl << endl;
	list.remove("of");
	printList(list);

	return 0;
}



// parseString(): take a sentence as input, remove punctuation, split into individual words.
void parseString(string sentence, LinkedList<string>& list) {
	int startIndex = 0;
	int numChars = 0;
	bool firstLetter = true;
	string word = "";

	// Loop through each char of the sentence.
	for (int i = 0; i < sentence.size(); i++) {
		// If a char is a punctuation mark, get rid of it.
		if (!isalpha(sentence.at(i)) && !isspace(sentence.at(i))) {
			sentence.erase(i, 1);
		}
	}

	// Get the updated length of the sentence.
	int length = sentence.size();

	for (int i = 0; i < sentence.size(); i++) {
		// If the char is a letter...
		if (isalpha(sentence.at(i))) {
			// If we're looking at the first letter of a word, record the startIndex.
			if (firstLetter) {
				startIndex = i;
				firstLetter = false;
			}
			// Increment the number of chars in the word.
			numChars++;
		}
		// If the char is a space...
		else {
			// Get the word: substring starting at startIndex, with numChars number of chars.
			word = sentence.substr(startIndex, numChars);
			// Add the word on the end of the list.
			list.add(word);
			// Reset values for the next word.
			firstLetter = true;
			numChars = 0;
		}
	}
	// After the for-loop, add the last word to the list. 
	word = sentence.substr(startIndex, numChars);
	list.add(word);
}

// printList(): iterate through the linked list and print each word.
void printList(LinkedList<string> sentence) {
	for (int i = 0; i < sentence.getSize(); i++) {
		cout << sentence.get(i) << " ";
	}
	cout << endl;
}

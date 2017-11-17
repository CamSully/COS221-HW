/* heightTester.cpp
* Author: Cameron Sullivan
* Date: 11-5-17
* 
* This code tests the functionality of the height() function in BST.h.
*/

#include <iostream>
#include <string>
#include "BST.h"
using namespace std;

// Prototype.
void parseString(string, BST<string>&);


int main() {
	
	// Create a binary search tree.
	BST<string> tree;

	cout << "Cameron Sullivan - COS 221 - HW8 Output" << endl << endl;
	
	const string sentence = "DURING the whole of a dull, dark, and soundless day in the autumn of the year, when the clouds hung oppressively low in the heavens, I had been passing alone, on horseback, through a singularly dreary tract of country; and at length found myself, as the shades of the evening drew on, within view of the melancholy House of Usher.";

	// Parse the string to remove punctuation and load words into the tree.
	cout << "Original sentence: " << endl << sentence << endl << endl;
	parseString(sentence, tree);
        cout << "The strings have been loaded into a binary search tree." << endl;
	cout << "BST Height: " << tree.height() << endl << endl;

	// Print the tree using inorder traversal.
	cout << "BST sentence (inorder traversal): " << endl;
	tree.inorder();
	cout << endl;

	return 0;
}



// parseString(): take a sentence as input, remove punctuation, split into individual words, load into the BST.
void parseString(string sentence, BST<string>& tree) {
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
			// Insert the word into the BST.
			tree.insert(word);
			// Reset values for the next word.
			firstLetter = true;
			numChars = 0;
		}
	}
	// After the for-loop, insert the last word into the tree. 
	word = sentence.substr(startIndex, numChars);
	tree.insert(word);
}

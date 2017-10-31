/* Cam Sully
*
*/

#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList<string> list;

void parseString(string);

int main() {
	const string sentence = "DURING the whole of a dull, dark, and soundless day in the autumn of the year, when the clouds hung oppressively low in the heavens, I had been passing alone, on horseback, through a singularly dreary tract of country; and at length found myself, as the shades of the evening drew on, within view of the melancholy House of Usher.";

	parseString(sentence);
	
//	for (int i = 0; i < list.getSize(); i++) {
//		cout << list.get(i) << endl;
//	}

	return 0;
}

void parseString(string sentence) {
	int startIndex;
	int stopIndex;
	bool firstLetter = true;
	string word;

	for (int i = 0; i < sentence.size(); i++) {
		if (isalpha(sentence.at(i))) {
			if (firstLetter) {
				startIndex = i;
				firstLetter = false;
			}
		}
		else {
			stopIndex = i - 1;
			word = sentence.substr(startIndex, stopIndex);
			list.add(word);
			cout << word << endl;
			firstLetter = true;
		}
	}
}

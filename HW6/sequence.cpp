/* COS 221 - Cameron Sullivan - HW6
* In-progress: Add cases: User only enters a 0, user enters non-ints.
*/

#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

int main() {
	vector<int> series;
	int input;

	cout << "Enter a series of numbers, terminated by 0:" << endl;

	// Allow the user to enter integers to fill the vector.
	while (true) {
		cin >> input;
		cout << typeid(input).name();
		if (typeid(input).name() == "string") {
			cout << "ERROR" << endl;
			break;
		}

		if (input == 0) {
			break;
		}
		
		series.push_back(input);

	}
		int count = 1;
		int maxIndex = 0;
		int maxCount = 1;
		int maxVal;

	if (series.at(0) == NULL) {
		count = 0;
		maxIndex = 0;
		maxCount = 0;
	}

	else {
		// Iterate through the vector and find the longest sequence of the same number.
		for (int index = 0; index < series.size() - 1; index++) {
			
			if (series.at(index) == series.at(index + 1)) {
				count++;
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
	}

	// Diagnostics.
//	cout << "Vector size: " << series.size() << endl;
//	cout << "Vector contents: ";
//	for (int i = 0; i < series.size(); i++) {
//		cout << series.at(i) << " ";
//	}
//	cout << endl;

	cout << "The longest same-number sequence starts at index " << maxIndex << " with " << maxCount << " values of " << maxVal << "." << endl;

	return 0;
}


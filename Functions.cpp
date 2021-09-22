#include "Functions.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
//Gotta include those libraries for programming

/* My second official Computer Science Project, called "The UW-Stout lottery" where you put in 5 numbers 1-99, and then lottery is randomly generated.
* Finally, the user's numbers are compared to the lottery's and the number of matches is output.
* Completed by Preston October 22, 2020
*/

void SelectionSort(int lotNumber[], int size) {

	int minIndex; // value of the current minimum index

	double temp; // Holds the extra value during swap

	//LOOKS for the place to swap
	for (int i = 0; i < size; i++) {
		minIndex = i;

		//search through the rest of the array for the smallest value
		for (int j = i; j < size; j++) {
			if (lotNumber[j] < lotNumber[minIndex]) {
				minIndex = j;
			}
		}

		//swap
		temp = lotNumber[minIndex];
		lotNumber[minIndex] = lotNumber[i];
		lotNumber[i] = temp;
	}
	for (int i = 0; i < size; i++) {
		cout << lotNumber[i] << ", ";
	}
	cout << endl;
}

void userInput(int array[], int numTimes) {
userInputBeginning: // function goes to this if user inputs something other than what they are asked to
	for (int i = 0; i < numTimes; i++) {
		cin >> array[i]; // User enters their 5 lucky numbers
		if ((array[i] < 1) || (array[i] > 99)) { //Validation of input. If the user inputs something that isn't 1-99, alerts them and resets their input
			cout << array[i] << " Is not a valid input." << endl;
			cout << "You're not funny, you broke the lottery." << endl;
			cout << "Enter new lottery numbers" << endl;
			cin.clear();
			cin.ignore();
			i = 0;
			goto userInputBeginning; // So the function doesn't break, begin the function anew
		}
	}
	cout << endl; // Make it a little neater
}

void lottoGenerator(int array[], int numTimes) {
	for (int i = 0; i < numTimes; i++) { // For amount of numbers in the lottery,
		array[i] = rand() % 99 + 1; // Picks a random number 1-99
	}
}

int compareLotteries(int userArray[], int lottery[], int numTimes) {
	int matches = 0; // Obviously there's no matches yet, so it's 0
	
	for (int i = 0; i < numTimes; i++) {
		if (userArray[i] == lottery[i]) {
			++matches;
		}
	}
	//What the above for loop does is go through both arrays and check if there are any matches betweent the two.
	// If there are, then the amount of matches is incremented
	return matches;
}

void countWinnings(int matches) {
	switch (matches) { // Switch statement instead of if statement for cleaner reading
	case 1: // If there is one match, do this
		cout << "Congratulations! You had 1 match. You won $5!" << endl;
		break;
	case 2: // If there are two matches, do this
		cout << "Congratulations! You had 2 matches. You won $51!" << endl;
		break;
	case 3: // If there are three matches, do this
		cout << "Congratulations! You had 3 matches. You won $50!" << endl;
		break;
	case 4: // If there are four matches, do this
		cout << "Congratulations! You had 4 matches. You won $100!" << endl;
		break;
	case 5: // If there are five matches, do this
		cout << "Congratulations! You had 5 matches. You won $500!" << endl;
		break;
	default: // If there are no matches, do this
		cout << "You had 0 matches. Better luck next time!" << endl;
		break;
	}

}

//end of functions
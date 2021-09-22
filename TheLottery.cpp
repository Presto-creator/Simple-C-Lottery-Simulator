/*
Lottery Simulator created by: 
Preston Leigh
on October 24, 2020
As the name suggests, this program simulates a 5 number lottery
*/

#include <iostream>
#include "Functions.h"
#include <iomanip>
#include <time.h>
//Gotta include those libraries/files to make it all work!

using namespace std; // Don't want to use std:: for anything

int main() {
	const int NUM_LOTTOS = 5; // # of #'s in lottery
	int lottery[NUM_LOTTOS]; // The lottery's numbers
	int userNums[NUM_LOTTOS]; // The player's numbers
	int numMatches; // # of matches
	srand(time(NULL)); // Allows the program to pick random numbers for library

	cout << "Welcome to the UW-Stout Lottery! Input 5 numbers 1-99 as your lottery ticket! Good luck!" << endl;
	//Gotta welcome them with a nice warm message and show them what they're getting themselves into

	userInput(userNums, NUM_LOTTOS);
	//This function gets the input from the user for their 5 lucky numbers

	lottoGenerator(lottery, NUM_LOTTOS);
	//This function randomly generates 5 numbers for the library

	cout << "The lottery's winning numbers are: " << endl;
	SelectionSort(lottery, NUM_LOTTOS);
	// This function takes in, sorts, and outputs the lottery's numbers

	cout << "Your selected numbers are: " << endl;
	SelectionSort(userNums, NUM_LOTTOS);
	// This function takes in, sorts, and outputs the user's numbers

	numMatches = compareLotteries(userNums, lottery, NUM_LOTTOS);
	// This function returns the amount of matches between the user and lottery's numbers, and stores it in the variable numMatches

	countWinnings(numMatches);
	//This function takes the number of matches as input and alerts the user to their winnings

	cout << endl << "Thanks for playing!" << endl;
	//Do I need to explain this one? 

	return 0;
	//Exits the program
}

//End of program
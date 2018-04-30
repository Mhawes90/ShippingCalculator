// C6 P6.cpp : Defines the entry point for the console application.
/********************************************************************************
 * by Mark Hawes																*
 * Shipping Cost Calculator														*
 * User enters weight and shipping distance and it calculates and returns the	*
 * total shipping cost															*
 * last updated: 7/18/17														*
 ********************************************************************************/

#include "stdafx.h"
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

// function prototypes
void welcomeMessage();
void getShippingInfo(double &weight, double &distance);
double calculateCharge(double weight, double distance);
double getRate(double weight);
void checkValid(double &shipCharge);
bool continueMessage();
void endMessage();
void closeMessage();

/********************************************
 *				main function				*
 * main function for Shipping Cost Program	*
 ********************************************/
int main()
{
	// set precision output for decimals
	cout << fixed;
	cout << setprecision(2);
	double weight = 0, distance = 0, shipCharge = 0; // declares variables
	int iterations = 0; // count iterations of program. Just because.

	// welcomes user and explains how to exit program
	welcomeMessage();

	do {
		iterations++; // counts the number of times running through loop/program - not really used
		// get values from user
		getShippingInfo(weight, distance);

		// if weight is 0 close program
		if (weight == 0)
			continue;
		
		shipCharge = calculateCharge(weight, distance); // get shipping cost and save it as a local value

		// check that shipping cost is a valid amount -- IE not $0 or less than $0
		checkValid(shipCharge);

		if (!continueMessage())
			weight = 0;
	} while (weight != 0);

	endMessage(); // indicates program is complete to user

	closeMessage(); // stops program from auto closing at the end
    return 0;
}

/********************************************
 *				welcomeMessage				*
 * welcomes user, explains how to exit		*
 ********************************************/
void welcomeMessage() {
	cout << "\nWelcome to the Shipping Cost Calculator.\n";
	cout << "\nEnter weight as 0 to exit the program.\n\n";
}

/********************************************
 *				getShippingInfo				*
 * prompts for user to input weight	and 	*
 * distance, then sends it back to main		*
 ********************************************/
void getShippingInfo(double &weight, double &distance){
	// weight prompt
	cout << "Enter the weight(in kilograms) of the package to be shipped: \n";
	cin >> weight;

	// if weight is 0 then don't even prompt for distance
	if (weight != 0) {
		// distance prompt
		cout << "\nEnter the distance(in Miles) package is to be shipped: \n";
		cin >> distance;
	} //end if
}

/********************************************
 *				calculateCharge				*
 * takes in weight and distance to			*
 * calculate and return shipping costs		*
 ********************************************/
double calculateCharge(double weight, double distance) {
	return getRate(weight) * (distance / 500.0);
}

/********************************************
 *				getRate						*
 * takes in weight to return rate per 500	*
 * miles									*
 ********************************************/
double getRate(double weight) {
	// check to see if weight is a valid number -- aka above zero
	// if number is below zero it is assumed the user meant the absolute value
	if (weight < 0)
		weight = abs(weight);

	// return rate based on weight
	if (weight <= 2)
		return 3.10;
	else if (weight > 2 && weight <= 6)
		return 4.20;
	else if (weight > 6 && weight <= 10)
		return 5.30;
	else if (weight > 10)
		return 6.40;
	else
		return 0;
}

/********************************************
 *				checkValid					*
 * check that shipping charge is valid num	*
 ********************************************/
void checkValid(double &shipCharge) {
	if (shipCharge > 0)
		cout << "\nThe cost for this shipment is: $" << shipCharge << endl << endl;
	else
		cout << "\nParameters invalid. Please try again later.\n\n";
}

/********************************************
 *				continueMessage				*
 * asks user if they would like to run		*
 * program again							*
 ********************************************/
bool continueMessage() {
	char userIn;

	cout << "\nWould you like to check another package?(y/n)\n";
	cin >> userIn;

	if (tolower(userIn) == 'y') {
		system("cls");
		return true;
	}
	else
		return false;
}

/********************************************
 *				endMessage					*
 * message to user indicating program end	*
 ********************************************/
void endMessage() {
	cout << "\nThank you for using the Shipping Cost Calculator.";
	cout << "\nHave a nice day!\n";
}

/********************************************
 *				closeMessage				*
 * final statement of program that stops it	*
 * from closing until user enters input		*
 ********************************************/
void closeMessage() {
	cout << "\nPress enter to exit program.\n";
	getchar();
	getchar();
}
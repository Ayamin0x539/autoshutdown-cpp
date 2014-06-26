// Timed Shutdown.cpp : Defines the entry point for the console application.
// Written by Ayamin.
// The user will input a time in seconds to shut down the computer.
// The computer will count down, and then shut down after this time.
// The number entered must not be negative, and a warning will be given to the user if the inputed time is less than 10 seconds.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <string>

using namespace std;

void zerocheck(int *x) {
	while (*x <= 0) { // must be greater than 0
		cout << "Please enter a value greater than 0." << endl;
		Sleep(1000);
		cin >> *x;
	}
}



int main(int argc, char *argv[]) {
	bool prompt;
	int i;
	int *p = &i; // we'll pass this pointer to i into zerocheck(int).
	int c = 0; // count up from c to i; when c hits i, shut down.


	system("color 0D");
	cout << "How many seconds until this computer shuts down?: ";
	Sleep(1000);

	cin >> i;
	zerocheck(p);
	if (i <= 10)
		prompt = 0;
	else prompt = 1;
	while (!prompt) {
		string answer;
		cout << "Your computer will shut down in less than 10 seconds. In fact, it will shut down in " << i << " seconds." << endl;
		cout << "Do you still wish to continue? Type \"yes\" or \"no\"" << endl;
		cin >> answer;
		while (answer != "yes" && answer != "no") {
			cout << "Please type \"yes\" or \"no\"" << endl;
			cin >> answer;
		}
		if (answer == "yes") {
			prompt = 1;
		} 
		else if (answer == "no") {
			cout << "How many seconds until this computer shuts down then?" << endl;
			cin >> i;
			zerocheck(p);
			if (i <= 10)
				prompt = 0;
			else prompt = 1;
		}
	}

	cout << "You entered: " << i << endl;
	
	for (c; c <= i; c++) {
		float secs = (i - c) % 60;
		float mins = floor((i - c) / 60 % 60);
		float hours = floor((i - c) / 3600);
		cout << "Shutting down in " << hours << " hour(s), " << mins << " minute(s), and " << secs << " second(s)..." << endl;
		Sleep(1000);
	}

	cout << "System shutting down!" << endl;

	Sleep(1000);

	system("shutdown /s /t 1");
}

/*
Reference material.
system("color XY") - X produces background, Y produces font

0 = black
1 = blue
2 = green
3 = aqua
4 = red
5 = purple
6 = yellow
7 = white
8 = gray
9 = light blue
A = light green
B = light aqua
C = light red
D = light purple
E = light yellow
F = bright white
*/

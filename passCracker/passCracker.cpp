// passCracker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

string crackPass(string pass);
int iterateChar(string &cr);

const char charMin = 33, charMax = 126;
string pass;

int main() {
	string cracked;
	cout << "Enter a password to crack: ";
	cin >> pass;

	time_t startTime = time(0);

	// for (int i = 33; i <= 126; i++) {
	// 	cout << i << " = " << static_cast<char>(i) << endl;
	// }

	cracked = crackPass(pass);
	time_t endTime = time(0);
	cout << "SUCCESS! The password you entered is: " << cracked << endl;
	cout << "Process took " << difftime(endTime, startTime) << " seconds to complete." << endl;
	return 0;
}

string crackPass(string pass) {
	string cracked = "";

	//Iterate through possible strings of various lengths up to 32 chars
	for (int x = 1; x < 32; x++) {
		cracked.assign(x, static_cast<char>(32));
		while (cracked != pass) {
			if (iterateChar(cracked) != 0) {
				break;
			}
			cout << "Checking: " << cracked << endl;
		}
		if (cracked == pass) {
			break;
		}
	}

	return cracked;
}

int iterateChar(string &cr) {
	for (int i = cr.length() - 1; i >= 0; i--) {
		if (cr.at(i) >= charMax) {
			cr[i] = charMin;
			if (i == 0) {
				return 1;
			}
		} else {
			cr[i] = cr.at(i) + 1;
			return 0;
		}
	}
	return 0;
}


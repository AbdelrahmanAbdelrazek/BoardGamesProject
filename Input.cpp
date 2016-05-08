#include "Input.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
int getInt() {
	string input;
	int number;
	while (true) {
		getline(cin, input);
		stringstream myStream(input);
		if (myStream >> number)
			break;
		cout << "Invalid number, please try again" << endl;
	}
	return number;
}

char getChar() {
	string input;
	char c;
	while (true) {
		getline(cin, input);
		stringstream myStream(input);
		if (input.size() == 1 && myStream >> c)
			break;
		cout << "Invalid charcter, please try again" << endl;
	}
		return c;
}
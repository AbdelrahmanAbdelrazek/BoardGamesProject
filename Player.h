#pragma once
#include <string>
using namespace std;

class Player {
private:
	string _name;
	char _symbol;
public:
	Player(const string &name, char symbol) :_name{ name }, _symbol{ symbol } {}
	string getName() { return _name; }
	char getSymbol() { return _symbol; }
	Player() {}
};

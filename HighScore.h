#pragma once
#include <string>
using namespace std;
class HighScore {
private:
	int Score;
	string Player;
public:
	void SetScore(int x) { Score = x; }
	int GetScore() { return Score; }
	void SetPlayer(string s) { Player=s; }
	string GetPlayer() { return Player; }
};
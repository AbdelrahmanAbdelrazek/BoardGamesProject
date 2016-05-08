#pragma once
#include "HighScore.h"
bool SortHighScores(HighScore a, HighScore b)
{
	return a.GetScore() < b.GetScore();
}

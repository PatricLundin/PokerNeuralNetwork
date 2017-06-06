#pragma once

#include "PokerEngine.h"
#include <vector>

class Utils
{
public:
	Utils() {}
	~Utils() {}
	static void StartingHandToNetInput(Hand &startinghand, vector<float> &inputVal);
	static void InitializeInputVals(vector<float> &inputVal);
private:

};
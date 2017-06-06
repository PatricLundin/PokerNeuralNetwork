#include "Utils.h"

void Utils::StartingHandToNetInput(Hand &startinghand, vector<float> &inputVal) {
	inputVal[startinghand.first - 1] = 1.0f;
	inputVal[startinghand.second - 1] = 1.0f;
}

void Utils::InitializeInputVals(vector<float> &inputVal) {

	// Starting hand 
	for (unsigned i = 0; i < 52; ++i) {
		inputVal.push_back(0.0f);
	}

	// Flop 
	for (unsigned i = 0; i < 52; ++i) {
		inputVal.push_back(0.0f);
	}

	// Turn
	for (unsigned i = 0; i < 52; ++i) {
		inputVal.push_back(0.0f);
	}

	// River
	for (unsigned i = 0; i < 52; ++i) {
		inputVal.push_back(0.0f);
	}

	// Stack
	inputVal.push_back(0.5f);

	// Pot
	inputVal.push_back(0.0f);

	// Facing Action
	inputVal.push_back(1.0f); // Starting action
	inputVal.push_back(0.0f); // 0 for check 1 for not check
	inputVal.push_back(0.0f); // facing bet in % of total chips

}
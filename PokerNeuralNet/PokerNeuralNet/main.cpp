#include <vector>
#include "PokerEngine.h"
#include <fstream>
#include "Utils.h"

using namespace std;


int main()
{
	PokerEngine pokerEngine;
	vector<Hand> holdings = pokerEngine.startHand();
	vector<float> inputValsFirstNet;
	Utils::InitializeInputVals(inputValsFirstNet);
	Utils::StartingHandToNetInput(holdings[0], inputValsFirstNet);

	ofstream log;
	log.open("log.txt");
	log << "holdings size: " << holdings.size() << endl;

	log << "first holding: " << holdings[0].first << "," << holdings[0].second << endl;
	log << "second holding: " << holdings[1].first << "," << holdings[1].second << endl;

	for (unsigned i = 0; i < inputValsFirstNet.size(); ++i) {
		log << inputValsFirstNet[i];
	}

	log.close();
}
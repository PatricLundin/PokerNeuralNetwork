#include <vector>
#include "PokerEngine.h"
#include <fstream>

using namespace std;


int main()
{
	PokerEngine pokerEngine;

	vector<Hand> holdings = pokerEngine.startHand();

	ofstream log;
	log.open("log.txt");
	log << "holdings size: " << holdings.size() << endl;

	log << "first holding: " << holdings[0].first << "," << holdings[0].second << endl;
	log << "second holding: " << holdings[1].first << "," << holdings[1].second << endl;
	log.close();
}
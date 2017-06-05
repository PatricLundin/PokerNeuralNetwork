#pragma once

#include <vector>
#include <stdlib.h>

using namespace std;

struct Hand {
	unsigned first;
	unsigned second;
};

class PokerEngine
{
public:
	PokerEngine();
	vector<Hand> startHand();
	~PokerEngine();
private:
	Hand generateHandWithRemoval(vector<Hand> &cardRemoval);
	unsigned getRandomCard();
	unsigned getRandomCardWithRemoval(vector<unsigned> &cardRemoval);
};



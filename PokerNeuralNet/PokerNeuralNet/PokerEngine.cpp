#include "PokerEngine.h"


PokerEngine::PokerEngine()
{
}

vector<Hand> PokerEngine::startHand()
{
	vector<Hand> hands;
	hands.push_back(generateHandWithRemoval(hands));
	hands.push_back(generateHandWithRemoval(hands));
	return hands;
}

Hand PokerEngine::generateHandWithRemoval(vector<Hand> &cardRemoval)
{
	Hand holding;
	vector<unsigned> cardsAllocated;
	for (unsigned i = 0; i < cardRemoval.size(); ++i) {
		cardsAllocated.push_back(cardRemoval[i].first);
		cardsAllocated.push_back(cardRemoval[i].second);
	}
	holding.first = getRandomCardWithRemoval(cardsAllocated);
	holding.second = getRandomCardWithRemoval(cardsAllocated);
	return holding;
}

unsigned PokerEngine::getRandomCard() 
{
	return rand() % 52 + 1;
}

unsigned PokerEngine::getRandomCardWithRemoval(vector<unsigned> &cardRemoval)
{
	unsigned randomizedCard = rand() % 52 + 1;
	for (unsigned i = 0; i < cardRemoval.size(); ++i) {
		if (randomizedCard == cardRemoval[i]) {
			getRandomCardWithRemoval(cardRemoval);
		}
	}
	cardRemoval.push_back(randomizedCard);
	return randomizedCard;
}

PokerEngine::~PokerEngine()
{
}
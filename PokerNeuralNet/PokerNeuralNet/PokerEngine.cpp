#include "PokerEngine.h"
#include <random>


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
	return getRandomNumber();
}

unsigned PokerEngine::getRandomCardWithRemoval(vector<unsigned> &cardRemoval)
{
	unsigned randomizedCard = getRandomNumber();
	for (unsigned i = 0; i < cardRemoval.size(); ++i) {
		if (randomizedCard == cardRemoval[i]) {
			randomizedCard = getRandomCardWithRemoval(cardRemoval);
		}
	}
	
	cardRemoval.push_back(randomizedCard);
	return randomizedCard;
}

unsigned PokerEngine::getRandomNumber()
{
	random_device rd;
	mt19937 engine(rd()); 
	uniform_int_distribution<int> dist(1,52);

	return (unsigned)dist(engine);
}

PokerEngine::~PokerEngine()
{
}
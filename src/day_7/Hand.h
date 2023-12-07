#pragma once

#include <string>

using namespace std;

enum class Type { five_of_a_kind, four_of_a_kind, full_house, three_of_a_kind, two_pair, one_pair, highest_card };

class Hand {
public:
	Hand(const string& _hand, const int& _bid) { hand = _hand; bid = _bid; makeEasy(); }
	Type GetType();
	int GetBid() { return bid; }
	bool operator<(Hand otherHand)
	{
		if (hand < otherHand.hand)
			return true;
		return false;
	}
private:
	void makeEasy();
	string hand;
	int bid;
};
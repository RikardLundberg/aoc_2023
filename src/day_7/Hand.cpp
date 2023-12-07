#include "Hand.h"
#include <algorithm>

// why doesn't this work???
/*
template<typename ... T>
constexpr bool all_equal(const T & ... args_)
{
	if ((sizeof...(args_)) < 2) return true;
	// for non recursive version
	const auto il_ = { args_ ... };
	// compare them all to the first
	auto first_ = *(il_.begin());
	// assumption
	bool rezult_{ true };
	for (auto&& elem_ : il_) {
		// yes I know, first cycle compares first_ to itself ...
		rezult_ = rezult_ && (first_ == elem_);
		// short circuit-ing
		if (!rezult_) break;
	}
	return rezult_;
};
*/

bool all_equal(const char& one, const char& two, const char& three, const char& four, const char& five)
{
	if (one == two && two == three && three == four && four == five)
		return true;
	return false;
}

bool all_equal(const char& one, const char& two, const char& three, const char& four)
{
	if (one == two && two == three && three == four)
		return true;
	return false;
}

bool all_equal(const char& one, const char& two, const char& three)
{
	if (one == two && two == three)
		return true;
	return false;
}

bool isFiveKind(const string& tmp, int jokerCount)
{
	if (all_equal(tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]))
		return true;
	else if (jokerCount == 1 && all_equal(tmp[1], tmp[2], tmp[3], tmp[4]))
		return true;
	else if (jokerCount == 2 && all_equal(tmp[2], tmp[3], tmp[4]))
		return true;
	else if (jokerCount == 3 && tmp[3] == tmp[4])
		return true;
	else if (jokerCount == 4)
		return true;
	return false;
}

bool isFourKind(const string& tmp, int jokerCount)
{
	if (all_equal(tmp[0], tmp[1], tmp[2], tmp[3]) || all_equal(tmp[1], tmp[2], tmp[3], tmp[4]))
		return true;
	if (jokerCount == 1 && (all_equal(tmp[1], tmp[2], tmp[3]) || all_equal(tmp[2], tmp[3], tmp[4])))
		return true;
	if (jokerCount == 2 && (tmp[2] == tmp[3] || tmp[3] == tmp[4]))
		return true;
	if (jokerCount == 3)
		return true;
	return false;
}

bool isOnePair(const string& tmp, int jokerCount)
{
	if (tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[2] == tmp[3] || tmp[3] == tmp[4])
		return true;
	if (jokerCount == 1)
		return true;
	return false;
}

bool isThreeKind(const string& tmp, int jokerCount)
{
	if (all_equal(tmp[0], tmp[1], tmp[2]) || all_equal(tmp[1], tmp[2], tmp[3]) || all_equal(tmp[2], tmp[3], tmp[4]))
		return true;
	if (jokerCount == 1 && isOnePair(tmp, 0))
		return true;
	if (jokerCount == 2)
		return true;
	return false;
}

bool isTwoPair(const string& tmp, int jokerCount)
{
	if ((tmp[0] == tmp[1] || tmp[1] == tmp[2]) && (tmp[2] == tmp[3] || tmp[3] == tmp[4]))
		return true;
	if (jokerCount == 1 && isOnePair(tmp, 0))
		return true;
	if (jokerCount == 2)
		return true;
	return false;
}

bool isFullHouse(const string& tmp, int jokerCount)
{
	if ((all_equal(tmp[0], tmp[1], tmp[2]) && tmp[3] == tmp[4]) || (all_equal(tmp[1], tmp[2], tmp[3]) && tmp[0] == tmp[4]) || (all_equal(tmp[2], tmp[3], tmp[4]) && tmp[0] == tmp[1]))
		return true;
	if (jokerCount == 1 && isTwoPair(tmp, 0))
		return true;
	if (jokerCount == 1 && isThreeKind(tmp, 0))
		return true;
	if (jokerCount == 2 && (tmp[2] == tmp[3] || tmp[3] == tmp[4]))
		return true;
	return false;
}



Type Hand::GetType()
{
	string tmp = hand;
	sort(tmp.begin(), tmp.end());
	int jokerCount = count(tmp.begin(), tmp.end(), '1');
	if (isFiveKind(tmp, jokerCount))
		return Type::five_of_a_kind;
	else if (isFourKind(tmp, jokerCount))
		return Type::four_of_a_kind;
	else if (isFullHouse(tmp, jokerCount))
		return Type::full_house;
	else if (isThreeKind(tmp, jokerCount))
		return Type::three_of_a_kind;
	else if (isTwoPair(tmp, jokerCount))
		return Type::two_pair;
	else if (isOnePair(tmp, jokerCount))
		return Type::one_pair;
	return Type::highest_card;
}

void Hand::makeEasy()
{
	std::replace(hand.begin(), hand.end(), 'T', 'B');
	std::replace(hand.begin(), hand.end(), 'J', '1');
	std::replace(hand.begin(), hand.end(), 'Q', 'D');
	std::replace(hand.begin(), hand.end(), 'K', 'E');
	std::replace(hand.begin(), hand.end(), 'A', 'F');
}

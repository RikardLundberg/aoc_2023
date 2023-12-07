#include "Hand.h"
#include <algorithm>

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

Type Hand::GetType()
{
	string tmp = hand;
	sort(tmp.begin(), tmp.end());
	if (all_equal(tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]))
		return Type::five_of_a_kind;
	else if (all_equal(tmp[0], tmp[1], tmp[2], tmp[3]) || all_equal(tmp[1], tmp[2], tmp[3], tmp[4]))
		return Type::four_of_a_kind;
	else if ((all_equal(tmp[0], tmp[1], tmp[2]) && tmp[3] == tmp[4]) || (all_equal(tmp[1], tmp[2], tmp[3]) && tmp[0] == tmp[4]) || (all_equal(tmp[2], tmp[3], tmp[4]) && tmp[0] == tmp[1]))
		return Type::full_house;
	else if (all_equal(tmp[0], tmp[1], tmp[2]) || all_equal(tmp[1], tmp[2], tmp[3]) || all_equal(tmp[2], tmp[3], tmp[4]))
		return Type::three_of_a_kind;
	else if ((tmp[0] == tmp[1] || tmp[1] == tmp[2]) && (tmp[2] == tmp[3] || tmp[3] == tmp[4]))
		return Type::two_pair;
	else if (tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[2] == tmp[3] || tmp[3] == tmp[4])
		return Type::one_pair;
	return Type::highest_card;
}

void Hand::makeEasy()
{
	std::replace(hand.begin(), hand.end(), 'T', 'B');
	std::replace(hand.begin(), hand.end(), 'J', 'C');
	std::replace(hand.begin(), hand.end(), 'Q', 'D');
	std::replace(hand.begin(), hand.end(), 'K', 'E');
	std::replace(hand.begin(), hand.end(), 'A', 'F');
}

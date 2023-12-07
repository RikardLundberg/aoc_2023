#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Hand.h"
#include "Common/ReadUtility.h"
#include <algorithm>

using namespace std;

void firstStar();
void secondStar();

vector<Hand> fiveKinds;
vector<Hand> fourKinds;
vector<Hand> fullHouses;
vector<Hand> threeKinds;
vector<Hand> twoPairs;
vector<Hand> onePairs;
vector<Hand> highCards;

void readInput()
{
    ifstream infile("input.txt");
    string line;
    while (getline(infile, line))
    {
        vector<string> split = ReadUtility::Split(line, ' ');
        Hand hand(split[0], stoi(split[1]));
        auto type = hand.GetType();
        switch (type)
        {
        case Type::five_of_a_kind:
            fiveKinds.push_back(hand);
            break;
        case Type::four_of_a_kind:
            fourKinds.push_back(hand);
            break;
        case Type::full_house:
            fullHouses.push_back(hand);
            break;
        case Type::three_of_a_kind:
            threeKinds.push_back(hand);
            break;
        case Type::two_pair:
            twoPairs.push_back(hand);
            break;
        case Type::one_pair:
            onePairs.push_back(hand);
            break;
        default:
            highCards.push_back(hand);
            break;
        }
    }
    sort(fiveKinds.begin(), fiveKinds.end());
    sort(fourKinds.begin(), fourKinds.end());
    sort(fullHouses.begin(), fullHouses.end());
    sort(threeKinds.begin(), threeKinds.end());
    sort(twoPairs.begin(), twoPairs.end());
    sort(onePairs.begin(), onePairs.end());
    sort(highCards.begin(), highCards.end());
}

int main(void)
{
    readInput();
    //firstStar(); don't want to redo read ... 
    secondStar();
}

void secondStar()
{
    long long total = 0;
    int rank = 1;
    for (int i = 0; i < highCards.size(); i++)
        total += highCards[i].GetBid() * rank++;
    for (int i = 0; i < onePairs.size(); i++)
        total += onePairs[i].GetBid() * rank++;
    for (int i = 0; i < twoPairs.size(); i++)
        total += twoPairs[i].GetBid() * rank++;
    for (int i = 0; i < threeKinds.size(); i++)
        total += threeKinds[i].GetBid() * rank++;
    for (int i = 0; i < fullHouses.size(); i++)
        total += fullHouses[i].GetBid() * rank++;
    for (int i = 0; i < fourKinds.size(); i++)
        total += fourKinds[i].GetBid() * rank++;
    for (int i = 0; i < fiveKinds.size(); i++)
        total += fiveKinds[i].GetBid() * rank++;

    cout << "1st : " << total;
}

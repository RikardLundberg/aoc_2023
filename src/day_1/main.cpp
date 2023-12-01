#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

int firstStar();
int secondStar();

void replaceIfLower(const size_t& cand, size_t& start_pos, int& lowest, const int& value)
{
    if(cand == std::string::npos)
        return;
    if(cand < start_pos) {
        start_pos = cand;
        lowest = value;
    }
}

void replaceIfHigher(const size_t& cand, size_t& start_pos, int& highest, const int& value)
{
    if(cand == std::string::npos)
        return;
    if(cand > start_pos) {
        start_pos = cand;
        highest = value;
    }
}

int getLowestDigit(const std::string& str)
{
    int lowest;
    size_t start_pos = str.length();
    replaceIfLower(str.find("one"), start_pos, lowest, 1);
    replaceIfLower(str.find("two"), start_pos, lowest, 2);
    replaceIfLower(str.find("three"), start_pos, lowest, 3);
    replaceIfLower(str.find("four"), start_pos, lowest, 4);
    replaceIfLower(str.find("five"), start_pos, lowest, 5);
    replaceIfLower(str.find("six"), start_pos, lowest, 6);
    replaceIfLower(str.find("seven"), start_pos, lowest, 7);
    replaceIfLower(str.find("eight"), start_pos, lowest, 8);
    replaceIfLower(str.find("nine"), start_pos, lowest, 9);
    replaceIfLower(str.find("1"), start_pos, lowest, 1);
    replaceIfLower(str.find("2"), start_pos, lowest, 2);
    replaceIfLower(str.find("3"), start_pos, lowest, 3);
    replaceIfLower(str.find("4"), start_pos, lowest, 4);
    replaceIfLower(str.find("5"), start_pos, lowest, 5);
    replaceIfLower(str.find("6"), start_pos, lowest, 6);
    replaceIfLower(str.find("7"), start_pos, lowest, 7);
    replaceIfLower(str.find("8"), start_pos, lowest, 8);
    replaceIfLower(str.find("9"), start_pos, lowest, 9);
    return lowest;
}

int getHighestDigit(const std::string& str)
{
    int highest;
    size_t start_pos = 0;
    replaceIfHigher(str.rfind("one"), start_pos, highest, 1);
    replaceIfHigher(str.rfind("two"), start_pos, highest, 2);
    replaceIfHigher(str.rfind("three"), start_pos, highest, 3);
    replaceIfHigher(str.rfind("four"), start_pos, highest, 4);
    replaceIfHigher(str.rfind("five"), start_pos, highest, 5);
    replaceIfHigher(str.rfind("six"), start_pos, highest, 6);
    replaceIfHigher(str.rfind("seven"), start_pos, highest, 7);
    replaceIfHigher(str.rfind("eight"), start_pos, highest, 8);
    replaceIfHigher(str.rfind("nine"), start_pos, highest, 9);
    replaceIfHigher(str.rfind("1"), start_pos, highest, 1);
    replaceIfHigher(str.rfind("2"), start_pos, highest, 2);
    replaceIfHigher(str.rfind("3"), start_pos, highest, 3);
    replaceIfHigher(str.rfind("4"), start_pos, highest, 4);
    replaceIfHigher(str.rfind("5"), start_pos, highest, 5);
    replaceIfHigher(str.rfind("6"), start_pos, highest, 6);
    replaceIfHigher(str.rfind("7"), start_pos, highest, 7);
    replaceIfHigher(str.rfind("8"), start_pos, highest, 8);
    replaceIfHigher(str.rfind("9"), start_pos, highest, 9);
    return highest;
}

int main(void) {
    firstStar();
    secondStar();
}

int secondStar()
{
    std::ifstream infile("input");
    int total = 0;
    std::string line;

    while(std::getline(infile, line))
    {
        int low = getLowestDigit(line);
        int high = getHighestDigit(line);
        total += low * 10;
        total += high;
    }

    std::cout << "2st Total: " << total << std::endl;
}

int firstStar()
{
    std::ifstream infile("input");
    int total = 0;
    std::string line;

    while(std::getline(infile, line))
    {
        std::vector<int> ints;
        for(char c : line)
        {
            if(c >= 48 && c <= 57)
            {
                ints.push_back(c-48);
            }
        }
        if(ints.size() > 0)
        {
            total += ints[0] * 10;
            total += ints[ints.size() - 1];
        }
    }

    std::cout << "1st Total: " << total << std::endl;

}

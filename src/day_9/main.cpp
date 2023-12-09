#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Common/ReadUtility.h"

using namespace std;

void firstStar();
void secondStar();

vector<vector<int>> inputs;

void readInput()
{
    ifstream infile("input.txt");
    string line;
    while (getline(infile, line))
    {
        vector<string> strings = ReadUtility::Split(line, ' ');
        vector<int> inputLine;
        for (string str : strings)
            inputLine.push_back(stoi(str));
        inputs.push_back(inputLine);
    }
}

int main()
{
    readInput();
    firstStar();
    secondStar();
}

void firstStar()
{
    long long total = 0;
    for (int i = 0; i < inputs.size(); i++)
    {
        vector<int> currentInput = inputs[i];
        vector<int> lastValueHist;
        lastValueHist.push_back(currentInput.back());
        
        while (lastValueHist.back() != 0)
        {
            vector<int> iteration;
            int previous = currentInput[0];
            for (int j = 1; j < currentInput.size(); j++)
            {
                iteration.push_back(currentInput[j] - previous);
                previous = currentInput[j];
            }
            lastValueHist.push_back(iteration.back());
            currentInput.clear();
            for (int itrVal : iteration)
                currentInput.push_back(itrVal);
        }

        for (int lastVal : lastValueHist)
            total += lastVal;
    }
    cout << "1st : " << total << endl;
}

void secondStar()
{

}

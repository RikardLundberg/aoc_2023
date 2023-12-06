#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int firstStar();
int secondStar();

int main(void)
{
    firstStar();
    secondStar();
}

int firstStar()
{
    ifstream infile("input");
    string val;
    vector<int> ints;
    while (infile >> val)
    {
        try{ ints.push_back(stoi(val)); } catch (...) {} 
    }

    int solutions = 1;
    for(int i = 0; i < (int)ints.size()/2; i++)
    {
        auto time = ints[i];
        auto dist = ints[i + ints.size()/2];
        int j = 0;
        int moveTime = time;
        while (j * moveTime <= dist)
        {
            j++;
            moveTime--;
        }

        solutions *= (time+1) - j*2;
    }
    
    cout << "1st total: " << solutions << endl;
}

int secondStar()
{
}
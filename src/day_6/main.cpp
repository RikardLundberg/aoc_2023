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
        try
        {
            ints.push_back(stoi(val));
        }
        catch (...)
        {
        }
    }

    int solutions = 1;
    for (int i = 0; i < (int)ints.size() / 2; i++)
    {
        auto time = ints[i];
        auto dist = ints[i + ints.size() / 2];
        int j = 0;
        int moveTime = time;
        while (j * moveTime <= dist)
        {
            j++;
            moveTime--;
        }

        solutions *= (time + 1) - j * 2;
    }

    cout << "1st total: " << solutions << endl;
}

long currentRecord = 0;
void findCurrentRecord(const long long &low, const long long &high, const long long &dist, const long &maxTime)
{
    if (high - low < 2)
    {
        currentRecord = low;
        return;
    }
    long long search = (long long)(high - low) / 2 + low;
    long long searchDist = search * (maxTime - search);
    if (dist == searchDist)
        currentRecord = search;
    else if (dist < searchDist)
        findCurrentRecord(low, search - 1, dist, maxTime);
    else
        findCurrentRecord(search + 1, high, dist, maxTime);
}

int secondStar()
{
    ifstream infile("input");
    string val;
    long long time = 0;
    long long dist = 0;
    string det = "";
    while (infile >> val)
    {
        if (val[0] >= 48 && val[0] <= 57)
        {
            det += val;
        }
        else if (val[0] == 'D')
        {
            time = stoll(det);
            det = "";
        }
    }
    dist = stoll(det);

    findCurrentRecord(0, time, dist, time);
    long solutions = time - currentRecord * 2 - 1;

    cout << "1st total: " << solutions << endl;
}
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int firstStar();
int secondStar();

bool isOnlyInt(const string &str)
{
    for (int i = 0; i < str.length(); i++)
        if (str[i] < 48 || str[i] > 57)
            return false;
    return true;
}

vector<int> getSortedNumberSplit(const string &str)
{
    vector<int> nbrs;
    size_t pos = str.find(' ');
    size_t startPos = 0;
    while (pos != string::npos)
    {
        string token = str.substr(startPos, pos - startPos);
        if (token != "" && isOnlyInt(token))
            nbrs.push_back(stoi(token));
        startPos = pos + 1;
        pos = str.find(' ', startPos);
    }
    string token = str.substr(startPos);
    if (token != "" && isOnlyInt(token))
        nbrs.push_back(stoi(token));
    sort(nbrs.begin(), nbrs.end());
}

int main(void)
{
    firstStar();
    secondStar();
}

int firstStar()
{
    ifstream infile("input");
    int total = 0;
    string line;
    while (getline(infile, line))
    {
        vector<int> nbrs = getSortedNumberSplit(line);
        int addTotal = 0;
        int previous = -1;
        for (int i = 0; i < nbrs.size(); i++)
        {
            if (nbrs[i] == previous)
            {
                if (addTotal == 0)
                    addTotal = 1;
                else
                    addTotal *= 2;
            }
            previous = nbrs[i];
        }
        total += addTotal;
    }
    cout << "1st total: " << total << endl;
}

int secondStar()
{
}
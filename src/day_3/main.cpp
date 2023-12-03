#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

vector<vector<char>> charMatrix;
int readInput()
{

    ifstream infile("input");

    string line;
    while (getline(infile, line))
    {
        vector<char> row;
        for (char c : line)
            row.push_back(c);
        charMatrix.push_back(row);
    }
}

int firstStar();
int secondStar();

int main(void)
{
    readInput();
    firstStar();
    // secondStar();
}

int secondStar()
{
}

bool checkAdjacency(const int &i, const int &j, const string &number)
{
    bool notHighestOnRow = charMatrix[i].size() > j + 1;
    bool notLowestOnRow = j - (int)number.length() >= 0;

    if (notHighestOnRow && charMatrix[i][j + 1] != '.')
        return true;
    if (notLowestOnRow && charMatrix[i][j - (int)number.length()] != '.')
        return true;

    int rowStart = notLowestOnRow ? j - (int)number.length() : j - (int)number.length() + 1;
    int rowEnd = notHighestOnRow ? j + 1 : j;

    if (i != 0)
    {
        for (int top = rowStart; top <= rowEnd; top++)
            if (charMatrix[i - 1][top] != '.')
                return true;
    }
    if (i != charMatrix.size() - 1)
    {
        for (int bot = rowStart; bot <= rowEnd; bot++)
            if (charMatrix[i + 1][bot] != '.')
                return true;
    }
    return false;
}

int firstStar()
{
    int total = 0;
    for (int i = 0; i < charMatrix.size(); i++)
    {
        string number = "";
        for (int j = 0; j < charMatrix[0].size(); j++)
        {
            char c = charMatrix[i][j];
            if (c >= 48 && c <= 57)
            {
                number += c;
            }
            else
            {
                if(number != "" && checkAdjacency(i, j - 1, number))
                    total += stoi(number);

                number = "";
            }
            if(j+1 == charMatrix[0].size() && number != "" && checkAdjacency(i, j, number))
                    total += stoi(number);
        }
    }

    cout << "1st sum: " << total << endl;
}
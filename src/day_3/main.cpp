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
    secondStar();
}

bool isNumber(char c)
{
    if (c >= 48 && c <= 57)
        return true;
    return false;
}

string getBackwardNumber(const int &i, const int &j)
{
    string retVal = "";
    int ti = i, tj = j;
    while (tj >= 0 && isNumber(charMatrix[ti][tj]))
    {
        retVal += charMatrix[ti][tj--];
    }
    reverse(retVal.begin(), retVal.end());
    return retVal;
}

string getForwardNumber(const int &i, const int &j)
{
    string retVal = "";
    int ti = i, tj = j;
    while (tj < charMatrix.size() && isNumber(charMatrix[ti][tj]))
    {
        retVal += charMatrix[ti][tj++];
    }
    return retVal;
}

void assignFirstSecond(const string str, int &first, int &second)
{
    if (str == "")
        return;

    if (first == 0)
        first = stoi(str);
    else if (second == 0)
        second = stoi(str);
}

bool checkAdjacencyForNumbers(const int &i, const int &j, int &first, int &second)
{
    assignFirstSecond(getBackwardNumber(i, j - 1), first, second);
    assignFirstSecond(getForwardNumber(i, j + 1), first, second);


    if (i != 0)
    {
        if(isNumber(charMatrix[i - 1][j]))
        {
            string b1 = getBackwardNumber(i - 1, j);
            string b2 = getForwardNumber(i - 1, j + 1);
            if (b1 != "")
                assignFirstSecond(b1 + b2, first, second);
        }
        else
        {
            assignFirstSecond(getForwardNumber(i - 1, j + 1), first, second);
            assignFirstSecond(getBackwardNumber(i - 1, j - 1), first, second);
        }
    }
    
    if (i != charMatrix.size() - 1)
    {
        if(isNumber(charMatrix[i + 1][j]))
        {
            string b1 = getBackwardNumber(i + 1, j);
            string b2 = getForwardNumber(i + 1, j + 1);
            if (b1 != "")
                assignFirstSecond(b1 + b2, first, second);
        }
        else
        {
            assignFirstSecond(getForwardNumber(i + 1, j + 1), first, second);
            assignFirstSecond(getBackwardNumber(i + 1, j - 1), first, second);
        }
    }

    if (first != 0 && second != 0)
        return true;
    return false;
}

int secondStar()
{
    int total = 0;
    for (int i = 0; i < charMatrix.size(); i++)
    {
        for (int j = 0; j < charMatrix[0].size(); j++)
        {
            char c = charMatrix[i][j];
            if (c == '*')
            {
                int first = 0, second = 0;
                if (checkAdjacencyForNumbers(i, j, first, second))
                    total += first * second;
            }
        }
    }

    cout << "2nd sum: " << total << endl;
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
                if (number != "" && checkAdjacency(i, j - 1, number))
                    total += stoi(number);

                number = "";
            }
            if (j + 1 == charMatrix[0].size() && number != "" && checkAdjacency(i, j, number))
                total += stoi(number);
        }
    }

    cout << "1st sum: " << total << endl;
}
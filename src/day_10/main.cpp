#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

vector<string> input;
int start_x;
int start_y;

void readInput()
{
	ifstream infile("input.txt");
	string line;
	while (getline(infile, line))
	{
		if (line.find('S') != string::npos)
		{
			start_y = input.size();
			start_x = line.find('S');
		}
		input.push_back(line);
	}
}

bool validLeft(char c)
{
	if (c == 'L' || c == 'F' || c == '-')
		return true;
	return false;
}

bool validRight(char c)
{
	if (c == '7' || c == 'J' || c == '-')
		return true;
	return false;
}

bool validTop(char c)
{
	if (c == '7' || c == '|' || c == 'F')
		return true;
	return false;
}

bool validBot(char c)
{
	if (c == 'L' || c == 'J' || c == '|')
		return true;
	return false;
}

enum diff {xUp, xDown, yUp, yDown};
void firstStar()
{
	diff lastDiff = xUp;
	int newX = start_x;
	int newY = start_y;
	if (start_x > 0 && validLeft(input[start_y][start_x - 1]))
	{
		newX--;
		lastDiff = xDown;
	}
	else if (start_x + 1 != input[start_y].length() && validRight(input[start_y][start_x + 1]))
	{
		newX++;
		lastDiff = xUp;
	}
	else if (start_y != 0 && validTop(input[start_y - 1][start_x]))
	{
		newY--;
		lastDiff = yUp;
	}
	else if (start_y + 1 != input.size() && validBot(input[start_y + 1][start_x]))
	{
		newY++;
		lastDiff = yDown;
	}

	bool stop = false;
	int pipeCount = 1;
	vector<char> path;
	while (!stop)
	{
		pipeCount++;
		if (pipeCount % 500 == 0)
			std::cout << "pipecount: " << pipeCount <<endl;
		// S 7 J F L - | .
		path.push_back(input[newY][newX]);
		switch (input[newY][newX])
		{
		case 'S':
			stop = true;
			break;
		case '7':
			if (lastDiff == yUp)
			{
				newX--;
				lastDiff = xDown;
			}
			else
			{
				newY++;
				lastDiff = yDown;
			}
			break;
		case 'F':
			if (lastDiff == yUp)
			{
				newX++;
				lastDiff = xUp;
			}
			else
			{
				newY++;
				lastDiff = yDown;
			}
			break;
		case 'J':
			if (lastDiff == yDown)
			{
				newX--;
				lastDiff = xDown;
			}
			else
			{
				newY--;
				lastDiff = yUp;
			}
			break;
		case 'L':
			if (lastDiff == yDown)
			{
				newX++;
				lastDiff = xUp;
			}
			else
			{
				newY--;
				lastDiff = yUp;
			}
			break;
		case '-':
			newX = lastDiff == xDown ? newX - 1 : newX + 1;
			break;
		case '|':
			newY = lastDiff == yUp ? newY - 1 : newY + 1;
			break;
		}

	}
	std::cout << "1st " << (pipeCount) / 2 << " and pc=" << pipeCount << endl;

}

int main()
{
	readInput();
	firstStar();
}

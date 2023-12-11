#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

struct galaxy {
	int x;
	int y;
};

vector<int> colCost;
vector<string> universe;
vector<galaxy> galaxies;

void readInput()
{
	vector<bool> colChecks;
	ifstream infile("input.txt");
	string line;
	while (getline(infile, line))
	{
		while (colCost.size() < line.size())
			colCost.push_back(2);

		bool allDots = true;
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == '#') {
				galaxy gal;
				gal.y = universe.size();
				gal.x = i;
				galaxies.push_back(gal);
				allDots = false;
				colCost[i] = 1;
			}
		}
		universe.push_back(line);
		if (allDots)
			universe.push_back(line);
	}
}

void firstStar()
{
	long long total = 0;
	for (int i = 0; i < galaxies.size(); i++)
	{
		for (int j = i; j < galaxies.size(); j++)
		{
			long pairDist = abs(galaxies[j].y - galaxies[i].y);
			int start = min(galaxies[i].x, galaxies[j].x);
			int end = max(galaxies[i].x, galaxies[j].x);
			for (int x = start; x < end; x++)
				pairDist += colCost[x];
			total += pairDist;
		}
	}

	cout << "1st sum: " << total << endl;
}

int main()
{
	readInput();
	firstStar();
}

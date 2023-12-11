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
vector<int> rowCost;
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
			colCost.push_back(1000000);
		while (rowCost.size() < line.size())
			rowCost.push_back(1000000);

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
		if (!allDots)
			rowCost[universe.size() - 1] = 1;
	}
}

void starSeeking()
{
	long long total = 0;
	for (int i = 0; i < galaxies.size(); i++)
	{
		for (int j = i; j < galaxies.size(); j++)
		{
			long long pairDist = 0;
			int startY = min(galaxies[i].y, galaxies[j].y);
			int endY = max(galaxies[i].y, galaxies[j].y);
			for (int y = startY; y < endY; y++)
				pairDist += rowCost[y];

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
	starSeeking();
}

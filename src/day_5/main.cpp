#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Common/ReadUtility.h"

using namespace std;

void firstStar();
void secondStar();

class mapSegment
{
public:
    long long dest;
    long long source;
    long long length;

    long long Translate(const long long& number)
    {
        if (number >= source && source + length > number)
            return dest + (number - source);
        else
            return number;
    }
};

struct map
{
    vector<mapSegment> segments;
};

vector<map> maps;
vector<long long> seeds;

void readInput()
{
    ifstream infile("input.txt");
    string line;
    getline(infile, line);
    vector<string> strings = ReadUtility::Split(line, ' ');
    for (int i = 1; i < strings.size(); i++)
        seeds.push_back(stoll(strings[i]));

    vector<mapSegment> inputSegments;
    getline(infile, line);
    getline(infile, line);
    while (getline(infile, line))
    {
        if (line.find("map:") != string::npos)
        {
            map map;
            for (int i = 0; i < inputSegments.size(); i++)
                map.segments.push_back(inputSegments[i]);
            maps.push_back(map);
            inputSegments.clear();
        }
        else if (line != "")
        {
            vector<string> strings = ReadUtility::Split(line, ' ');
            mapSegment segment;
            segment.dest = stoll(strings[0]);
            segment.source = stoll(strings[1]);
            segment.length = stoll(strings[2]);
            inputSegments.push_back(segment);
        }
    }
    map map;
    for (int i = 0; i < inputSegments.size(); i++)
        map.segments.push_back(inputSegments[i]);
    maps.push_back(map);
    inputSegments.clear();
}

int main(void)
{
    readInput();
    firstStar();
    secondStar();
}

void firstStar()
{
    long long lowestLocation = -1;
    for (int i = 0; i < seeds.size(); i++)
    {
        vector<long long> path;
        long long currentPlantThing = seeds[i];
        for (int j = 0; j < maps.size(); j++)
        {
            for (mapSegment seg : maps[j].segments)
            {
                long long potentialMatch = seg.Translate(currentPlantThing);
                if (potentialMatch != currentPlantThing) {
                    currentPlantThing = potentialMatch;
                    break;
                }
            }
            path.push_back(currentPlantThing);
        }
        if (lowestLocation == -1 || currentPlantThing < lowestLocation)
            lowestLocation = currentPlantThing;
    }

    cout << "1st total: " << lowestLocation << endl;
}

void secondStar()
{
    // sort possible locations from lowest to highest, 
    // check backwards if correspond to any seed
}

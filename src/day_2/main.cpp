#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

int firstStar();
int secondStar();

int main(void) {
    firstStar();
    secondStar();
}

bool replaceAllWithGeg(std::string& str, const std::string& replaceFrom)
{
    size_t start_pos = 0;
    while((start_pos = str.find(replaceFrom, start_pos)) != std::string::npos) {
        str.replace(start_pos, replaceFrom.length(), "geg");
    }
}

int secondStar()
{
    std::ifstream infile("input");
    int total = 0;
    std::string line;

    while(std::getline(infile, line))
    {
        int i = 0;
        while(line.find("red") != std::string::npos)
            replaceAllWithGeg(line, " " + std::to_string(++i) + " red");
        int product = i; i = 0;
        while(line.find("green") != std::string::npos)
            replaceAllWithGeg(line, " " + std::to_string(++i) + " green");
        product *= i; i = 0;
        while(line.find("blue") != std::string::npos)
            replaceAllWithGeg(line, " " + std::to_string(++i) + " blue");
        product *= i;
        total += product;
    }

    std::cout << "2st sum: " << total << std::endl;

}

int firstStar()
{
    std::ifstream infile("input");
    int total = 0;
    int game = 1;
    std::string line;

    while(std::getline(infile, line))
    {
        for(int i = 1; i < 13; i++)
            replaceAllWithGeg(line, " " + std::to_string(i) + " red");
        for(int i = 1; i < 14; i++)
            replaceAllWithGeg(line, " " + std::to_string(i) + " green");
        for(int i = 1; i < 15; i++)
            replaceAllWithGeg(line, " " + std::to_string(i) + " blue");

        if(line.find("blue") == std::string::npos && line.find("red") == std::string::npos && line.find("green") == std::string::npos)
            total += game;
        game++;
    }

    std::cout << "1st sum: " << total << std::endl;
}
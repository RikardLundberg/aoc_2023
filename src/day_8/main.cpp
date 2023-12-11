#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class node {
public:
    node* left;
    node* right;
    string name;
    string leftName;
    string rightName;
};

vector<node> allNodes;
string instructions;
node* currentNode;

void readInput()
{
    ifstream infile("input.txt");
    string line;

    getline(infile, line);
    instructions = line;
    getline(infile, line); //empty
    while (getline(infile, line))
    {
        string name = line.substr(0, line.find(' '));
        string left = line.substr(line.find('(') + 1, 3);
        string right = line.substr(line.find(',') + 2, 3);
        node node;
        node.name = name;
        node.leftName = left;
        node.rightName = right;
        allNodes.push_back(node);
    }

    int currentNodeIndex;
    for (int n = 0; n < allNodes.size(); n++)
    {
        for (int i = 0; i < allNodes.size(); i++) {
            if (allNodes[i].name == allNodes[n].leftName)
                allNodes[n].left = &allNodes[i];
            if (allNodes[i].name == allNodes[n].rightName)
                allNodes[n].right = &allNodes[i];
        }
        if (allNodes[n].name == "AAA")
            currentNode = &allNodes[n];
    }
}

void firstStar()
{
    long long steps = 0;
    int counter = 0;
    while (currentNode->name != "ZZZ")
    {
        if (instructions[counter] == 'L')
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;
        steps++;
        counter++;
        if (counter == instructions.size())
            counter = 0;
    }

    cout << "1st sum: " << steps << endl;
}

void secondStar() 
{

}

int main()
{
    readInput();
    firstStar();
    secondStar();
}

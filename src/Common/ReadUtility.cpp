#include "ReadUtility.h"

vector<string> ReadUtility::Split(const string& str, const char& separator)
{
    vector<string> strings;
    size_t pos = str.find(separator);
    size_t startPos = 0;
    while (pos != string::npos)
    {
        string token = str.substr(startPos, pos - startPos);
        if (token != "")
            strings.push_back(token);
        startPos = pos + 1;
        pos = str.find(separator, startPos);
    }
    string token = str.substr(startPos);
    if (token != "")
        strings.push_back(token);
    return strings;
}
#ifndef STRINGMANAGER_H
#define STRINGMANAGER_H

#include <iostream>
#include <vector>

using namespace std;

class StringManager
{
    string _str;

public:
    StringManager(string str);
    vector<string> separate_str(char separator);
};

#endif // STRINGMANAGER_H

#include "stringmanager.h"
#include<sstream>

StringManager::StringManager(string str) : _str(str)
{

}

vector<string> StringManager::separate_str(char separator)
{
    stringstream flow(_str);
    vector<string> fields;
    string part;

    while(getline(flow, part, separator))
    {
        fields.push_back(part);
    }
    return fields;
}

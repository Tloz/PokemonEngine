#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>

#define PARSER_VERSION "0.2"

using namespace std;

namespace Parser
{
    string version();
    vector<string> str_explode(string const & s, char delim = ';');
    vector<vector<string>> getTokensFromFile(string fileName, char delim = ';');

    string str_implode(vector<string> tokens, char delim = ';');
    void writeTokensToFile(vector<vector<string>> tokens, string filename);
}
#endif
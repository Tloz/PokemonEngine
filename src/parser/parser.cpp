#include "../../inc/parser.h"
#include <stdexcept>

string Parser::version()
{
    return PARSER_VERSION;
}

vector<string> Parser::str_explode(string const & s, char delim)
{
    vector<string> result;
    istringstream iss(s);

    for (string token; getline(iss, token, delim); )
    {
        result.push_back(move(token));
    }
    return result;
}

vector<vector<string>> Parser::getTokensFromFile(string fileName, char delimiter)
{
    bool verbose = false;
    if(verbose)
        cout << "Entering getTokensFromFile(" << fileName << ")" << endl ;
    /* declaring what we'll need :
     * string line -> the line beeing parsed
     * ifstream myfile -> the file that name has been given as parameter
     * vector <vector <string> > tokens -> the return value
     * 
     * Putting all line into tokens
     */
    string line;
    ifstream myfile(fileName);
    vector< vector<string> > tokens;
    if(verbose)
        cout << "Opening file " << fileName << " ... ";
    if(!myfile.is_open())
    {
        string str_err = "Unable to open file ";
        str_err += fileName;
        throw invalid_argument(str_err);
    }
    else
    {
        if(verbose)
            cout << "Done !" << endl;
        while (getline (myfile,line))
        {
            if(verbose)
                cout << "Parsing line '" << line << "'. " << endl;
            // If line is blank or start with # (comment)
            // then we don't parse it
            if((line.length() == 0) || (line.at(0) == '#'))
            {
                if(verbose)
                    cout << "Empty or comment, passing." << endl;;
                continue;
            }
            else
            {
                vector <string> tmptokens = str_explode(line, delimiter);
                if(verbose)
                    cout << "Adding token " << tmptokens[0] << " and its values.";
                tokens.push_back(tmptokens);
            }
            if(verbose)
                cout << endl;
        }
        if(verbose)
            cout << "Exiting getTokensFromFile(" << fileName << ")" << endl;
    }
    return tokens;
}

string Parser::str_implode(vector<string> tokens, char delim)
{
    // TODO: tweak something here to get rid of final delim
    string retval = "";
    for(auto i:tokens)
    {
        retval += i;
        retval += delim;
    }
    return retval;
}
void Parser::writeTokensToFile(vector<vector<string>> tokens, string fileName)
{
    // on ouvre le fichier, on écrit les tokens dedans, on ferme le fichier
    ofstream myfile(fileName);
    if(!myfile.is_open())
    {
        string str_err = "Unable to open file ";
        str_err += fileName;
        throw invalid_argument(str_err);
    }
    else
    {
        cout << "file open!" << endl;
        for(auto t:tokens)
        {
            myfile << str_implode(t) << endl;
        }
        myfile.close();
    }
}
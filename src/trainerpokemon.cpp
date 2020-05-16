#include "../inc/trainerpokemon.h"
#include <fstream>

TrainerPokemon::TrainerPokemon()
{
    
}

TrainerPokemon::TrainerPokemon(vector<vector<string>> specieTokens, vector<vector<string>> pokeTokens) : Pokemon(specieTokens)
{
    vector<vector<string> > unsedTokens;
    for(auto tokens:pokeTokens)
    {
        if(tokens[0] == "Name")
        {
            name(tokens[1]);
        }
        else if(tokens[0] == "DOName")
        {
            nameDO(tokens[1]);
        }
        else if(tokens[0] == "DOID")
        {
            noIDDO(stoi(tokens[1]));
        }
        else if(tokens[0] == "DOSecret")
        {
            noIDDOSecret(stoi(tokens[1]));
        }
        else if(tokens[0] == "Origin")
        {
            origin(tokens[1]);
        }
        else if(tokens[0] == "IPV")
        {
            m_ipv = PersonalityValue(stoi(tokens[1]));
        }
        else if(tokens[0] == "Gender")
        {
            m_gender = Gender(stoi(tokens[1]));
        }
        else if (tokens[0] == "metDate")
        {
            m_metDate = tokens[1];
        }
        else if (tokens[0] == "metPlace")
        {
            m_metPlace = tokens[1];
        }
        else if (tokens[0] == "metLevel")
        {
            m_metLevel = stoi(tokens[1]);
        }
        else if (tokens[0] == "ballUsed")
        {
            m_ballID = stoi(tokens[1]);
        }
        else if (tokens[0] == "currentLP")
        {
            m_currentLP = stoi(tokens[1]);
        }
        else if (tokens[0] == "currentPX")
        {
            m_px = stoi(tokens[1]);
        }
        else if (tokens[0] == "currentLevel")
        {
            m_level = stoi(tokens[1]);
        }
        else if(tokens[0] == "IV")
        {
            for (int i = 0; i < 6; ++i)
            {
                m_IV[i] = stoi(tokens[2]);
            }
        }
        else if(tokens[0] == "EV")
        {
            for (int i = 0; i < 6; ++i)
            {
                m_EV[i] = stoi(tokens[2]);
            }
        }
        else if(tokens[0] == "Move")
        {
            addMove(stoi(tokens[2]), stoi(tokens[3]), stoi(tokens[4]));
        }        
        else
        {
            unsedTokens.push_back(tokens);
        }
    }
    computeStats();
    if(unsedTokens.size() > 0)
    {
        cout << "Unused tokens: ";
        for(auto token:unsedTokens)
            cout << token[0] << "; ";
        cout << endl;
    }
}

TrainerPokemon::~TrainerPokemon()
{

}

void TrainerPokemon::print()
{
    cout << name();
    if(name() != specieName())
    {
        cout << " (" << specieName() << ")";
    }
    cout << endl << endl;
    cout << "Rencontré le ";
    cout << metDate(); // provoque une bad_alloc
    cout << " à ";
    cout << metPlace(); // provoque une bad_alloc
    cout << " au niveau ";
    cout << metLevel();
    cout << " et capturé par ";
    cout << nameDO(); // ne provoque pas d'erreur mais récupère le nom d'une attaque
    cout << " (";
    cout << noIDDO();
    cout << "/";
    cout << noIDDOSecret();
    cout << ")";
    cout << endl << endl;

    cout << "------- Statistiques -------" << endl;
    cout << "Points de vie: " << LP() << "/" << maxLP() << endl;
    cout << "ATK: " << atk() << "   SpeATK: " << speAtk() << endl;
    cout << "DEF: " << def() << "   SpeDef: " << speDef() << endl;
    cout << "Speed: " << speed() << endl;
    cout << "----------------------------" << endl << endl;

    cout << "--------- Attaques ---------" << endl;
    for(auto atk:moves())
    {
        atk.print();
        cout << endl;
    }
    cout << "----------------------------" << endl;
}

string TrainerPokemon::name()
{
    return m_name;
}

string TrainerPokemon::fileName(string sep)
{
    string fname = "";
    fname += to_string(specieID());
    if(variant() != 0)
    {
        fname += "-";
        fname += to_string(variant());
    }
    fname += sep;

    fname += name();
    fname += sep;

    fname += nameDO();
    fname += sep;

    fname += to_string(noIDDO());
    fname += to_string(noIDDOSecret());
    fname += sep;

    fname += metDate(false);
    return fname;
}

vector<vector<string>> TrainerPokemon::tokens()
{
    vector<vector<string>> retval;
    vector<string> tmp;

    tmp.push_back(string("SpecieID"));
    tmp.push_back(to_string(specieID()));
    retval.push_back(tmp);
    tmp.clear();

    tmp.push_back(string("VariantID"));
    tmp.push_back(to_string(variant()));
    retval.push_back(tmp);
    tmp.clear();

    tmp.push_back(string("Name"));
    tmp.push_back(name());
    retval.push_back(tmp);
    tmp.clear();

    tmp.push_back(string("DOName"));
    tmp.push_back(nameDO());
    retval.push_back(tmp);
    tmp.clear();

    tmp.push_back(string("DOID"));
    tmp.push_back(to_string(noIDDO()));
    retval.push_back(tmp);
    tmp.clear();

    tmp.push_back(string("DOSecret"));
    tmp.push_back(to_string(noIDDOSecret()));
    retval.push_back(tmp);
    tmp.clear();

    tmp.push_back(string("Origin"));
    tmp.push_back(string(origin()));
    retval.push_back(tmp);
    tmp.clear();

    tmp.push_back(string("IPV"));
    tmp.push_back(to_string(ipv().valueInt()));
    retval.push_back(tmp);
    tmp.clear();

    // tmp.push_back(string("Shiny"));
    // tmp.push_back(to_string(shiny()));
    // retval.push_back(tmp);
    // tmp.clear();

    tmp.push_back(string("Gender"));
    tmp.push_back(to_string(genderToInt(gender())));
    retval.push_back(tmp);
    tmp.clear();

    tmp.push_back(string("currentLP"));
    tmp.push_back(to_string(LP()));
    retval.push_back(tmp);
    tmp.clear();

    tmp.push_back(string("currentPX"));
    tmp.push_back(to_string(px()));
    retval.push_back(tmp);
    tmp.clear();

    tmp.push_back(string("currentLevel"));
    tmp.push_back(to_string(level()));
    retval.push_back(tmp);
    tmp.clear();

    tmp.push_back(string("metPlace"));
    tmp.push_back(metPlace());
    retval.push_back(tmp);
    tmp.clear();

    tmp.push_back(string("metDate"));
    tmp.push_back(metDate(false));
    retval.push_back(tmp);
    tmp.clear();

    tmp.push_back(string("metLevel"));
    tmp.push_back(to_string(metLevel()));
    retval.push_back(tmp);
    tmp.clear();

    for (int i = 0; i < 6; ++i)
    {
        tmp.push_back(string("IV"));
        tmp.push_back(to_string(i));
        tmp.push_back(to_string(IV(i)));
        retval.push_back(tmp);
        tmp.clear();
    }

    for (int i = 0; i < 6; ++i)
    {
        tmp.push_back(string("EV"));
        tmp.push_back(to_string(i));
        tmp.push_back(to_string(EV(i)));
        retval.push_back(tmp);
        tmp.clear();
    }

    for (int i = 0; i < 4; ++i)
    {
        tmp.push_back(string("Move"));
        tmp.push_back(to_string(i));
        tmp.push_back(to_string(moves().at(i).moveID()));
        tmp.push_back(to_string(moves().at(i).pp()));
        tmp.push_back(to_string(moves().at(i).ppmax()));
        retval.push_back(tmp);
        tmp.clear();
    }

    

    /*
    else if(tokens[0] == "IV")
    {
        for (int i = 0; i < 6; ++i)
        {
            m_IV[i] = stoi(tokens[2]);
        }
    }
    else if(tokens[0] == "EV")
    {
        for (int i = 0; i < 6; ++i)
        {
            m_EV[i] = stoi(tokens[2]);
        }
    }
    else if(tokens[0] == "Move")
    {
        addMove(stoi(tokens[2]), stoi(tokens[3]), stoi(tokens[4]));
    }
    */
    return retval;
}

void TrainerPokemon::name(string newName)
{
    m_name = newName;
}

int TrainerPokemon::ballID()
{
    return m_ballID;
}

void TrainerPokemon::ballID(int id)
{
    m_ballID = id;
}

int TrainerPokemon::metLevel()
{
    return m_metLevel;
}

void TrainerPokemon::metLevel(int lvl)
{
    m_metLevel = lvl;
}

string TrainerPokemon::nameDO()
{
    return m_nameDO;
}

void TrainerPokemon::nameDO(string name)
{
    m_nameDO = name;
}

string TrainerPokemon::metDate(bool nice)
{
    if(nice)
    {
        // Convertir la chaine  qui est au format YYYYMMDDHHmmSS
        // en DD/MM/YY hh:mm:ss
        return m_metDate;
    }
    else
    {
        return m_metDate;
    }
}

void TrainerPokemon::metDate(string date, bool nice)
{
    if(nice)
    {
        // Convertir la chaine  qui est au format DD/MM/YY hh:mm:ss
        // en YYYYMMDDHHmmSS
        m_metDate = date;
    }
    else
    {
        m_metDate = date;
    }
}

string TrainerPokemon::metPlace()
{
    return m_metPlace;
}

void TrainerPokemon::metPlace(string place)
{
    m_metPlace = place;
}

int TrainerPokemon::noIDDO()
{
    return m_noIDDO;
}

void TrainerPokemon::noIDDO(int DO)
{
    m_noIDDO = DO;
}

int TrainerPokemon::noIDDOSecret()
{
    return m_noIDDOSecret;
}

void TrainerPokemon::noIDDOSecret(int DOS)
{
    m_noIDDOSecret = DOS;
}

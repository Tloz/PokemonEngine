#include "../inc/savagepokemon.h"
#include "../inc/trainer.h"



SavagePokemon::SavagePokemon() : Pokemon()
{
    // cout << "Debug entering SavagePokemon ctor 1" << endl;
}

SavagePokemon::SavagePokemon(vector<vector<string> > specieTokens, int level) : Pokemon(specieTokens)
{
    // cout << "Debug entering SavagePokemon ctor 2" << endl;
    m_origin = "FR";
    m_name = specieName();
    m_ipv = PersonalityValue();
    m_gender = determineGender(genderBalance(), m_ipv.valueForGender());
    // check level and sets it
    if(level > 100)
        m_level = 100;
    else if(level < 0)
        m_level = 0;
    else
        m_level = level;

    // give a random number of IVs and no EV
    for (int i = 0; i < 6; ++i)
    {
        m_IV[i] = randFloatInRange(0, 31);
        m_EV[i] = 0;
    }
    computeStats();
    setLP(maxLP());
}

SavagePokemon::SavagePokemon(vector<vector<string> > specieTokens, vector<vector<string> > pokeTokens) : Pokemon(specieTokens)
{
    // cout << "Debug entering SavagePokemon ctor 3" << endl;
    vector<vector<string> > unsedTokens;
    for(auto tokens:pokeTokens)
    {
        if(tokens[0] == "Name")
        {
            name(tokens[1]);
        }
        else if(tokens[0] == "IPV")
        {
            m_ipv = PersonalityValue(stoi(tokens[1]));
        }
        else if(tokens[0] == "Gender")
        {
            m_gender = Gender(stoi(tokens[1]));
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
    setLP(maxLP());
    if(unsedTokens.size() > 0)
    {
        cout << "Unused tokens: ";
        for(auto token:unsedTokens)
            cout << token[0] << "; ";
        cout << endl;
    }
}


SavagePokemon::~SavagePokemon()
{

}

void SavagePokemon::print()
{
    cout << name();
    if((variant() != 0))
        cout << " " << variantName();
    cout << " Level " << level() << endl;
    cout << "Gender balance is " << genderBalance() << endl;
    cout << "Personality Value: " << ipv().valueInt() << " (";
    for (int i = 0; i < 32; ++i)
    {
        cout << ipv().valueBool()[i];
    }
    cout << ")" << endl;
    cout << "Value for gender = " << ipv().valueForGender() << " (";
    for (int i = 0; i < 8; ++i)
    {
        cout << ipv().valueForGenderBool()[i];
    }
    cout << ")" << endl;
    if(gender() != Gender::None)
    {
        cout <<"It's a ";
        if(gender() == Gender::Female)
            cout << "girl";
        else
            cout << "boy";
        cout << "! ";
    }
    cout << "Type: " << firstType().name();
    if (hasSecondType())
        cout << " and " << secondType().name();

    cout << endl;
    cout << "Stat, IV, EV" << endl;
    cout << "LP    : " << LP() << "/" << maxLP() << " (" << baseStat(0) << ", " << IV(0) << ", " << EV(0) << ")" << endl;
    cout << "ATK   : " << atk() << " (" << baseStat(1) << ", " << IV(1) << ", " << EV(1) << ")" << endl;
    cout << "DEF   : " << def() << " (" << baseStat(2) << ", " << IV(2) << ", " << EV(2) << ")" << endl;
    cout << "SpeAtk: " << speAtk() << " (" << baseStat(3) << ", " << IV(3) << ", " << EV(3) << ")" << endl;
    cout << "SpeDef: " << speDef() << " (" << baseStat(4) << ", " << IV(4) << ", " << EV(4) << ")" << endl;
    cout << "Speed : " << speed() << " (" << baseStat(5) << ", " << IV(5) << ", " << EV(5) << ")" << endl << endl;
}

int SavagePokemon::catchRate()
{
    return m_catchRate;
}

bool SavagePokemon::determineShinyness()
{
    // TODO
    unsigned int p1 = (ipv().valueForShiny1() xor ipv().valueForShiny2());
    unsigned int p2 = 0;
    //unsigned int p2 = ( Trainer::DO xor Trainer::DO_Secret);
    if ((p1 xor p2) < 8)
        return true;
    return false;
}

float SavagePokemon::catchBonus()
{
    switch(m_status)
    {
        case NonVolatileStatus_t::Burn :
        case NonVolatileStatus_t::Paralysis :
        case NonVolatileStatus_t::Poisoned :
        case NonVolatileStatus_t::PoisonedBadly :
            return 1.5;
            break;

        case NonVolatileStatus_t::Freeze :
        case NonVolatileStatus_t::Sleep :
            return 2.5;
            break;

        case NonVolatileStatus_t::None :
        default:
            return 1;
            break;
    }
}

#include "Parser.h"
#include "Account.h"

std::string Parser::ParseString(const std::string& str, const int type)  //do something if wrong
{
    std::string real_string = "";
    int i = 0;
    while (i < (int)str.size())
    {
        if (str[i] == ' ')
        {
            if (i != 0)
            {
                real_string += " ";
            }
            while (str[i] == ' ')
            {
                i++;
            }
        }
        else
        {
            real_string += str[i];
            i++;
        }
    }
    if (type == Type::Name)
    {
        pRegex = std::make_unique<NameRegex>();
        if (pRegex->if_matches(real_string))
        {
            return real_string;
        }
        else
        {
            return "Wrong username\t";
        }
    }
    else if (type == Type::Address)
    {
        pRegex = std::make_unique<AddressRegex>();
        if (pRegex->if_matches(real_string))
        {
            return real_string;
        }
        else
        {
            return "Wrong address\t";
        }
    }
    else if (type == Type::ID)
    {
        pRegex = std::make_unique<IDRegex>();
        if (pRegex->if_matches(real_string))
        {
            return real_string;
        }
        else
        {
            return "Wrong ID\t";
        }
    }
    else
    {
        return "Unknown exception";
    }
}

bool NameRegex::if_matches(std::string& s)
{
    return (std::regex_match(s, std::regex(matchUs)));
}

bool AddressRegex::if_matches(std::string& s)
{
    return (std::regex_match(s, std::regex(matchAdd)));
}

bool IDRegex::if_matches(std::string& s)
{
    return (std::regex_match(s, std::regex(matchID)));
}

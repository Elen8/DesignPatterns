
#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <iostream>
#include <regex>

#define regUser "(^[A-Za-z]*(([',.-][a-zA-Z])?[a-zA-Z ]*)*)+"
#define regAddress "[a-zA-Z]+[.]*[ ]*[a-zA-Z]*[ ]*([0-9]*[ ]*[a-zA-Z]*[ ]*[0-9]*[ ]*[a-zA-Z]*[ ]*)*"
#define regID "[0-9]+"

class RegexTemplate;

class IParser
{
public:
    virtual std::string ParseString(const std::string&, const int) = 0;
};

class Parser : public IParser
{
public:
    std::string ParseString(const std::string&, const int) override;
    std::unique_ptr<RegexTemplate> pRegex;
}; //bridge

class RegexTemplate
{
public:
    virtual bool if_matches(std::string&) = 0;

protected:
    std::string matchUs = regUser;
    std::string matchAdd = regAddress;
    std::string matchID = regID;
};

class NameRegex: public RegexTemplate
{
public:
    bool if_matches(std::string&);
};

class AddressRegex: public RegexTemplate
{
public:
    bool if_matches(std::string&);
};

class IDRegex: public RegexTemplate
{
public:
    bool if_matches(std::string&);
};

#endif // PARSER_H

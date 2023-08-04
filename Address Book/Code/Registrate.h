
#ifndef REGISTRATE_H
#define REGISTRATE_H

#include "DataBase.h"
#include "Parser.h"

class Registrate
{
public:
    Registrate(std::string&, std::string&);
    std::string Reg();

private:
    DB*                         db;
    std::string                 m_user;
    std::string                 m_address;
    std::unique_ptr<Parser>     prs;
};

#endif //REGISTRATE_H

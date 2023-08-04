#include "Account.h"

int Account::AID = 10000;

Account::Account(const std::string& user, const std::string& address)
{
    AUser = user;
    AAddress = address;
    AID += 1;
}

Account::Account(const std::string& user, const std::string& address, int ID)
{
    AUser = user;
    AAddress = address;
    AID = ID;
}

std::string Account::get_user()
{
    return AUser;
}

std::string Account::get_address()
{
    return AAddress;
}

int Account::get_ID()
{
    return AID;
}

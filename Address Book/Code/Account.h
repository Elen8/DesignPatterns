#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

class Account
{
public:
    Account(const std::string&, const std::string&, int);
    Account(const std::string&, const std::string&);

    std::string get_address();
    std::string get_user();
    int get_ID();

private:
    std::string     AUser;
    std::string     AAddress;
    static int      AID;
};

enum Type { Name, Address, ID };

#endif // ACCOUNT_H

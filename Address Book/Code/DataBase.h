
#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <vector>
#include "Account.h"

class DB //singleton
{
public:
    static DB* db_ins();

public:
    void AddAccount(Account);
    void SaveToFile();
    void ReadFromFile();
    int GetIDAt(const int);
    int GetCountofAccounts();
    std::string GetUserAt(const int);
    std::string GetAddressAt(const int);

private:
    static DB*              db;
    std::vector<Account>    m_accounts;
};

#endif //DATABASE_H

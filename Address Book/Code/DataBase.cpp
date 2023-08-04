
#include <fstream>
#include <string>
#include "DataBase.h"

DB* DB::db = 0;

DB* DB::db_ins()
{
    if (db == nullptr)
    {
        db = new DB();
    }
    return db;
}

void DB::AddAccount(Account acc)
{
    m_accounts.push_back(acc);
}

int DB::GetCountofAccounts()
{
    return m_accounts.size();
}

std::string DB::GetUserAt(const int idx)
{
    if (idx >= 0 && idx < (int)m_accounts.size())
    {
        return m_accounts[idx].get_user();
    }
    else
    {
        //exception out of range show in GUI
    }
}

std::string DB::GetAddressAt(const int idx)
{
    if (idx >= 0 && idx < (int)m_accounts.size())
    {
        return m_accounts[idx].get_address();
    }
    else
    {
        //exception out of range show in GUI
    }
}

int DB::GetIDAt(const int idx)
{
    if (idx >= 0 && idx < (int)m_accounts.size())
    {
        return m_accounts[idx].get_ID();
    }
}

void DB::SaveToFile()
{
    std::ofstream fin;
    std::string file = "C:\\Users\\tonoyan\\OneDrive - Synopsys, Inc\\Desktop\\AddressBook.txt";
    fin.open(file.c_str(), std::ios::in);
    for (int i = 0; i < (int)m_accounts.size(); i++)
    {
        fin << GetUserAt(i) + "|" + GetAddressAt(i) + "|" + std::to_string(10000 + i) + "|";
    }
    fin.close();
}

void DB::ReadFromFile()
{
    std::ifstream fin;
    std::string file = "C:\\Users\\tonoyan\\OneDrive - Synopsys, Inc\\Desktop\\AddressBook.txt";
    fin.open(file.c_str(), std::ios::in);
    std::string str;
    if (fin.is_open()) {
        str = std::string((std::istreambuf_iterator<char>(fin)), std::istreambuf_iterator<char>());
    }
    fin.close();
    int i = 0;
    while (i < str.size())
    {
        std::string User;
        std::string Address;
        std::string ID;
        while (str[i] != '|')
        {
            User += str[i];
            i++;
        }
        i++;
        while (str[i] != '|')
        {
            Address += str[i];
            i++;
        }
        i++;
        while (str[i] != '|')
        {
            ID += str[i];
            i++;
        }
        i++;
        Account acc(User, Address, std::stoi(ID));
        AddAccount(acc);
    }
}


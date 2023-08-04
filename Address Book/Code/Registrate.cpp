#include "Registrate.h"

Registrate::Registrate(std::string& user, std::string& address)
{
    m_user = user;
    m_address = address;
    prs = std::make_unique<Parser>();
}

std::string Registrate::Reg()
{
    m_user = prs->ParseString(m_user, Type::Name);
    m_address = prs->ParseString(m_address, Type::Address);
    if (m_user == "Wrong username\t" || m_user == "")
    {
        return "Invalid username\t";
    }
    else if (m_address == "Wrong address\t" || m_address == "")
    {
        return "Invalid address\t";
    }
    for (int i = 0; i < (int)m_user.size(); i++)
    {
        m_user[i] = std::toupper(m_user[i]);
    }

    for (int i = 0; i < (int)m_address.size(); i++)
    {
        m_address[i] = std::toupper(m_address[i]);
    }

    db = db->db_ins();
    Account acc(m_user, m_address);
    std::string ID = "Your ID is " + std::to_string(acc.get_ID()) + "\t";
    db->AddAccount(acc);
    return ID;
}

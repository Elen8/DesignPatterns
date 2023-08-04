
#include "Search.h"

Search::Search(const int type)
{

    search_type = type;
    db = db->db_ins();
    error_type = 0;
    prs = std::make_unique<Parser>();
}

void Search::SearchBy(int type, const std::string& search)
{
    std::string Search = prs->ParseString(search, search_type);
    if (Search == "Wrong username\t")
    {
        error_type = 1;
        return;
    }
    else if (Search == "Wrong address\t")
    {
        error_type = 2;
        return;
    }
    else if (Search == "Wrong ID\t")
    {
        error_type = 3;
        return;
    }
    else
    {
        std::string upsearch = Search;
        for (int i = 0; i < (int)upsearch.size(); i++)
        {
            upsearch[i] = std::toupper(upsearch[i]);
        }
        if (type == Type::Name)
        {
            for (int i = 0; i < db->GetCountofAccounts(); i++)
            {
                if (db->GetUserAt(i).find(upsearch) != std::string::npos)
                {
                    std::string r = db->GetUserAt(i) + " " + db->GetAddressAt(i) + " " + std::to_string(db->GetIDAt(i) - db->GetCountofAccounts() + 1 + i);
                    results.push_back(r);
                }
            }
        }
        else if (type == Type::Address)
        {
            for (int i = 0; i < db->GetCountofAccounts(); i++)
            {
                if (db->GetAddressAt(i).find(upsearch) != std::string::npos)
                {
                    std::string r = db->GetUserAt(i) + " " + db->GetAddressAt(i) + " " + std::to_string(db->GetIDAt(i) - db->GetCountofAccounts() + 1 + i);
                    results.push_back(r);
                }
            }
        }
        else if (type == Type::ID)
        {
            for (int i = 0; i < db->GetCountofAccounts(); i++)
            {
                if (db->GetIDAt(i) - db->GetCountofAccounts() + 1 + i == std::stoi(upsearch))
                {
                    std::string r = db->GetUserAt(i) + " " + db->GetAddressAt(i) + " " + std::to_string(db->GetIDAt(i) - db->GetCountofAccounts() + 1 + i);
                    results.push_back(r);
                }
            }
        }
        else
        {
            std::cout << "Unknown search type!";
        }
    }
}

std::string Search::GetResultAt(int i)
{
    return results[i];
}

int Search::CountOfResults()
{
    return results.size();
}

int Search::GetErrorType()
{
    return error_type;
}

void Search::ClearResults()
{
    results.erase(results.begin(), results.end());
}

void Search::PopFront()
{
    results.erase(results.begin());
}

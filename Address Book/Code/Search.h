
#ifndef SEARCH_H
#define SEARCH_H

#include "DataBase.h"
#include "Parser.h"
#include <vector>

class Search
{
public:
    Search(const int);

    void SearchBy(int, const std::string&);
    void ClearResults();
    void PopFront();
    int GetErrorType();
    int CountOfResults();
    std::string GetResultAt(int);

private:
    int                         search_type;
    int                         error_type;
    std::vector<std::string>    results;
    std::unique_ptr<Parser>     prs;
    DB*                         db;
};

#endif //SEARCH_H

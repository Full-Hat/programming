#ifndef ACCOUNTSET_H
#define ACCOUNTSET_H

#include "account.h"

#include <list>
#include <fstream>
#include <iostream>

class AccountSet
{
private:
    std::list<Account*> accountSet;

public:
    AccountSet();

    void addAccount(std::string name, std::string password);

    Account* find(std::string name);
    Account* login(std::string name, std::string password);

    void save(std::ofstream &fout);
    void load(std::istream &fin);

    bool remove(std::string name);

    friend std::ostream& operator<<(std::ostream& out, const AccountSet& set);

    ~AccountSet();
};

#endif // ACCOUNTSET_H

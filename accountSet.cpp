#include "accountSet.h"

void AccountSet::addAccount(std::string name, std::string password)
{
    Account* acc = new Account(name, password);
    accountSet.push_back(acc);
}

Account* AccountSet::find(std::string name)
{
    for(Account* acc : accountSet)
    {
        if(*acc == name)
        {
            return acc;
        }
    }

    return nullptr;
}

Account* AccountSet::login(std::string name, std::string password)
{
    for(Account* acc : accountSet)
    {
        if(*acc == std::pair<std::string, std::string>({name, password}))
        {
            return acc;
        }
    }

    return nullptr;
}

void AccountSet::save(std::ofstream &fout)
{
    for(auto acc : accountSet)
    {
        acc->saveData(fout);
    }
}

bool AccountSet::remove(std::string name)
{
    for(auto it = accountSet.begin(); it != accountSet.end(); ++it)
    {
        if(**it == name)
        {
            accountSet.erase(it);
            return true;
        }
    }

    return false;
}

void AccountSet::load(std::istream &fin)
{
    std::string name;
    while(std::getline(fin, name))
    {
        std::string password;
        std::getline(fin, password);
        //fin >> password;
        std::string balance;
        std::getline(fin, balance);
        //fin >> balance;
        std::string trSize;
        std::getline(fin, trSize);
        //fin >> trSize;
        Account* acc = new Account(name, password);
        acc->m_balance = std::stoi(balance);
        for(int i = 0; i < std::stoi(trSize); ++i)
        {
            Transaction t;
            std::getline(fin, t.from);
            //fin >> t.from;
            //fin >> t.sum;
            std::getline(fin, t.to);
            //fin >> t.to;
            std::string tempInt;
            std::getline(fin, tempInt);
            t.sum = std::stoi(tempInt);
            acc->m_history.push_back(t);
        }

        accountSet.push_back(acc);
    }
}

AccountSet::AccountSet()
{

}

AccountSet::~AccountSet()
{
    for(Account* acc : accountSet)
    {
        delete acc;
    }
}

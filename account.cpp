#include "account.h"

Account::Account(std::string name, std::string password):
    m_name(name), m_password(password), m_balance(bonus)
{
}

void Account::saveData(std::ofstream &fout)
{
    fout << m_name << "\n" << m_password << "\n" << m_balance << "\n";

    fout << m_history.size() << "\n";
    for(const Transaction &tr : m_history)
    {
        fout << tr;
    }
}

Account& operator-=(Account &acc, int sum)
{
    acc.m_balance -= sum;
    return acc;
}

Account& operator+=(Account &acc, int sum)
{
    acc.m_balance += sum;
    return acc;
} 

bool operator==(const Account &acc1, const std::string &name)
{
    return acc1.m_name == name;
}

bool operator==(const Account &acc1, std::pair<std::string, std::string> namePassword)
{
    return acc1.m_name == namePassword.first && acc1.m_password == namePassword.second;
}

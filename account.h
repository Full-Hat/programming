#ifndef DATABASE_H
#define DATABASE_H

#include "utils.h"

#include <iostream>
#include <fstream>

struct Transaction
{
    std::string from;
    std::string to;
    int sum;

    friend std::ostream& operator << (std::ostream &out, const Transaction &tr)
    {
        out << tr.from << "\n" << tr.to << "\n" << tr.sum << "\n";
        return out;
    }
};

class Account
{
public:
    static const int bonus = 10;

    std::string m_name;
    std::string m_password;
    int m_balance;
    std::vector<Transaction> m_history;

private:

public:
    Account(std::string name, std::string password);

    int getBalance() const { return m_balance; }
    std::string getName() const { return m_name; }
    void setName(std::string name) { m_name = name; }
    void setPassword(std::string password) { m_password = password; }

    void saveData(std::ofstream &fout);

    std::vector<Transaction> getTransactions() const { return m_history; }

    friend Account& operator-=(Account &acc, int sum);
    friend Account& operator+=(Account &acc, int sum);

    friend bool operator==(const Account &acc1, const Account &acc2);
    friend bool operator==(const Account &acc1, const std::string &name);
    friend bool operator==(const Account &acc1, std::pair<std::string, std::string> namePassword);
};

#endif // DATABASE_H

#ifndef INTERFACE_H
#define INTERFACE_H

#include <random>
#include <fstream>

#include "menu.h"
#include "accountSet.h"
#include "utils.h"

void startApp(std::string dataFileName);

void mainMenu(AccountSet &accs);

void login(AccountSet &accs);
void createAccount(AccountSet &accs);
void workWithAccount(AccountSet &accs, Account* acc);

void viewBalance(Account* acc);
void changeName(AccountSet &accs, Account* acc);
void changePassword(Account* acc);
void makeTransaction(AccountSet &accs, Account* acc);
void viewTransactionHistory(Account* acc);
void deleteAccount(AccountSet &accs, Account* acc);

#endif // INTERFACE_H

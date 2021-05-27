#include "interface.h"

void startApp(std::string dataFileName)
{
    AccountSet accs;
    std::ifstream fin(dataFileName);
    accs.load(fin);


    mainMenu(accs);
    std::ofstream fout(dataFileName);
    accs.save(fout);
    fout.close();

    std::cout << "Thanks for using our program!" << std::endl;
}

void mainMenu(AccountSet &accs)
{
    Menu menu;
    menu.fields = {"Exit", "Login", "Create account"};

    while(true)
    {
        menu.print();
        int userChoose = menu.execute();
        while(userChoose == -1)
        {
            std::cout << "Wrong value, choose one of the fields in menu: ";
            userChoose = menu.execute();
        }

        switch(userChoose)
        {
        case 0:
            return;
        case 1:
            login(accs);
            break;
        case 2:
            createAccount(accs);
            break;
        }
    }
}

void login(AccountSet &accs)
{
    std::cout << "To login add account inf (to exit write \"0\")\n";
    std::cout << "Name: ";
    std::string name;
    std::getline(std::cin, name);
    if(name == "0")
    {
        return;
    }
    std::cout << "Password: ";
    std::string password;
    std::getline(std::cin, password);

    Account* acc = accs.login(name, password);
    while(acc == nullptr)
    {
        std::cout << "Wrong name or password, try again: \n";
        std::cout << "Name: ";
        std::getline(std::cin, name);
        if(name == "0")
        {
            return;
        }
        std::cout << "Password: ";
        std::getline(std::cin, password);

        acc = accs.login(name, password);
    }

    std::cout << "Logged! :D \n";
    workWithAccount(accs, acc);
}

void workWithAccount(AccountSet &accs, Account* acc)
{
    Menu accMenu;
    accMenu.fields = {"Exit", "View balance", "Change name", "Change password", "Make transaction", "View transaction history", "Delete account"};

    while(true)
    {
        accMenu.print();
        int userChoose = accMenu.execute();
        while(userChoose == -1)
        {
            std::cout << "Wrong value, choose one of the fields in menu: ";
            userChoose = accMenu.execute();
        }

        switch (userChoose)
        {
        case 0:
            return;
        case 1:
            viewBalance(acc);
            break;
        case 2:
            changeName(accs, acc);
            break;
        case 3:
            changePassword(acc);
            break;
        case 4:
            makeTransaction(accs, acc);
            break;
        case 5:
            viewTransactionHistory(acc);
            break;
        case 6:
            deleteAccount(accs, acc);
            return;
        }
    }
}

void viewBalance(Account* acc)
{
    std::cout << "Your current balance: " << acc->getBalance() << "\n";
}

void changeName(AccountSet &accs, Account* acc)
{
    std::cout << "Enter new name: ";
    std::string name;
    std::getline(std::cin, name);

    while(accs.find(name) != nullptr)
    {
        std::cout << "Account with this name is also exist, try another: ";
        std::getline(std::cin, name);
    }
    acc->setName(name);
    std::cout << "Name changed! :D \n";
}

void changePassword(Account* acc)
{
    std::cout << "Enter new password: ";
    std::string password;
    std::getline(std::cin, password);

    acc->setPassword(password);
}

void makeTransaction(AccountSet &accs, Account* acc)
{
    if(acc->getBalance() == 0)
    {
        std::cout << "You have no money -> you can't make transactions\n";
        return;
    }

    // get acc
    std::cout << "Enter the name of target account to send money: ";
    std::string targetName;
    std::getline(std::cin, targetName);
    Account* targetAcc = accs.find(targetName);
    while(targetAcc == nullptr)
    {
        std::cout << "There is no such accounts, try another name: ";
        std::getline(std::cin, targetName);
        targetAcc = accs.find(targetName);
    }

    // get value
    std::cout << "Enter the transaction value: ";
    std::string stringValue;
    std::getline(std::cin, stringValue);
    int value;
    while(true)
    {
        while(!Utils::isNumber(stringValue))
        {
            std::cout << "You must enter integer type value, try again: ";
            std::getline(std::cin, stringValue);
        }

        value = std::stoi(stringValue);
        if(value > 0)
        {
            stringValue = "g";
            break;
        }
    }

    if(value > acc->getBalance())
    {
        std::cout << "Not enougth money to make transaction..\n";
        return;
    }

    *acc -= value;
    *targetAcc += value;
    Transaction tr;
    tr.from = acc->getName();
    tr.to = targetAcc->getName();
    tr.sum = value;
    acc->m_history.push_back(tr);
    targetAcc->m_history.push_back(tr);
}

void viewTransactionHistory(Account* acc)
{
    if(acc->getTransactions().size() == 0)
    {
        std::cout << "There was no transactions!\n";
        return;
    }

    std::cout << "Transaction history: \n";
    std::vector<Transaction> tr = acc->getTransactions();
    int i = 1;
    for(const Transaction& el : tr)
    {
        std::cout << "#" << i << ": \n";
        std::cout << "\tFrom: " << el.from << "\n";
        std::cout << "\tTo: " << el.to << "\n";
        std::cout << "\tSum: " << el.sum << "\n";
    }
}

void deleteAccount(AccountSet &accs, Account* acc)
{
    accs.remove(acc->getName());
    std::cout << "Removed! :D \n";
}

void createAccount(AccountSet &accs)
{
    std::cout << "To create account you must enter new acc inf\n";
    std::cout << "Name: ";
    std::string name;
    std::getline(std::cin, name);
    std::cout << "Password: ";
    std::string password;
    std::getline(std::cin, password);

    Account* acc = accs.find(name);
    while(acc != nullptr)
    {
        std::cout << "Account with this name is also exist, try another: ";
        std::getline(std::cin, name);
        acc = accs.find(name);
    }
    accs.addAccount(name, password);
    std::cout << "Successfully added! :D \n";
}

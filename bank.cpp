#include <iostream>
#include <fstream>

class Bank
{
public:
    std::string name;
    int accountnumber;
    float balance, deposit;

    Bank() : balance(0), deposit(0) {}
};

Bank b;
int option;

void CreateAccount()
{
    std::cout << "enter your name: ";
    std::cin >> b.name;

    std::cout << "enter the account number: ";
    std::cin >> b.accountnumber;

    std::cout << "Enter the amount of balance: ";
    std::cin >> b.balance;
}

void FileInput()
{
    std::ofstream bankFile("bank.txt", std::ios::out | std::ios::app);
    if (bankFile.is_open())
    {
        bankFile << b.name << "\n";
        bankFile << b.accountnumber << "\n";
        bankFile << b.balance << "\n";
        bankFile.close();
    }
    else
    {
        std::cout << "Error opening the file." << std::endl;
    }
}

void ShowAccount()
{
    std::cout << "Name: " << b.name << std::endl;
    std::cout << "Account Number: " << b.accountnumber << std::endl;
    std::cout << "Balance: " << b.balance << std::endl;
    std::cout << "---------------------" << std::endl;
}

void DepositMoney()
{
    std::cout << "enter the amount of money you want to deposit: ";
    std::cin >> b.deposit;
    b.balance = b.balance + b.deposit;
    std::cout << "Deposit successful." << std::endl;
    FileInput(); 
}

void WithdrawMoney()
{
    std::cout << "enter the amount of money you want to withdraw: ";
    float withdraw;
    std::cin >> withdraw;
    if (b.balance >= withdraw)
    {
        b.balance = b.balance - withdraw;
        std::cout << "Withdrawal successful." << std::endl;
        FileInput(); 
    }
    else
    {
        std::cout << "Insufficient balance." << std::endl;
    }
}

void CloseAccount()
{
    std::cout << "Are you sure you want to close the account? (Y/N): ";
    char confirmation;
    std::cin >> confirmation;

    if (confirmation == 'Y' || confirmation == 'y')
    {
        std::ofstream bankFile("bank.txt", std::ofstream::trunc);
        bankFile.close();
        std::cout << "Account closed successfully." << std::endl;
    }
}

void displayops()
{
    std::cout << "Welcome To The Bank" << std::endl;
    std::cout << "Press 1 to create account" << std::endl;
    std::cout << "Press 2 to show account" << std::endl;
    std::cout << "Press 3 to withdraw money" << std::endl;
    std::cout << "Press 4 to deposit money" << std::endl;
    std::cout << "Press 5 to close account" << std::endl;
    std::cout << "Press 6 to exit" << std::endl;
    std::cout << "Enter your choice (1-6): ";
    std::cin >> option;
}

void choice()
{
    do
    {
        displayops();
        switch (option)
        {
        case 1:
            CreateAccount();
            break;
        case 2:
            ShowAccount();
            break;
        case 3:
            WithdrawMoney();
            break;
        case 4:
            DepositMoney();
            break;
        case 5:
            CloseAccount();
            break;
        }
    } while (option >= 1 && option <= 5);
}

int main()
{
    choice();
    std::cout << "Exiting the bank." << std::endl;
    return 0;
}

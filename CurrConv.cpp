#include <iostream>
#include <stdlib.h>

int INR;

void welcome()
{
    std::cout << "Welcome to Currency Coverter" << std::endl;
}

void USD()
{   
    float rate = static_cast<float>(INR) / 82.06;
    std::cout << rate << std::endl;
}

void GBP()
{   
    float rate = static_cast<float>(INR) / 105.58;
    std::cout << rate << std::endl;
}
void EURO()
{   
    float rate = static_cast<float>(INR) /91.36;
    std::cout << rate << std::endl;
}
void AED()
{   
    float rate = static_cast<float>(INR) / 22.34;
    std::cout << rate << std::endl;
}
void AUD()
{   
    float rate = static_cast<float>(INR) / 55.0;
    std::cout << rate << std::endl;
}
void clear()
{
system ("PAUSE");
system ("CLS");
}
void cases()
{   
    int option;
    std::cout << "Select the currency to which you want to convert INR: " << std::endl;
    std::cout << "ENTER 1 for USD \n" "ENTER 2 for GBP \n"
    "ENTER 3 for EURO\n" "ENTER 4 for AED\n" "ENTER 5 for AUD" << std::endl;
    std::cin >> option;

    switch (option)
    {
    case 1:
        USD();
        break;
    case 2:
        GBP();
        break;
    case 3:
        EURO();
        break;
    case 4:
        AED();
        break;
    case 5:
        AUD();
        break;
    
    default:
    std::cout << "enter a valid number!" << std::endl;
        break;
    }
}

void InputINR()
{
    std::cout << "enter the amount of rupees you want to convert" << std::endl;  
    std::cin >> INR;
}

int main()
{   
    welcome();
    InputINR();
    cases();
    clear();
    return 0;
}
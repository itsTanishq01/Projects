#include <iostream>
#include <ctime>
#include <cstdlib>

class casino
{
public:
    float money, coins, bet;
    casino() : money(0), coins(0), bet(0) {}
};

casino c;

void userinput()
{
    std::cout << "Enter the amount of money you want to buy coins for: " << std::endl;
    std::cout << "50 Rupees = 1 coin" << std::endl;
    std::cin >> c.money;
    c.coins = c.money / 50;
    std::cout << "You have " << c.coins << " coins." << std::endl;
}

int rollDice()
{
    srand(time(0));
    return (rand() % 6) + 1;
}

void dicegame()
{
    std::cout << "Welcome to the dice game." << std::endl;
    while (c.coins > 0)
    {
        std::cout << "Enter the amount of coins you want to bet (Enter 0 to quit): ";
        std::cin >> c.bet;

        if (c.bet == 0)
        {
            std::cout << "You chose to quit the dice game." << std::endl;
            break;
        }

        if (c.bet > c.coins || c.bet < 0)
        {
            std::cout << "Invalid bet. Please place a valid bet." << std::endl;
            continue;
        }

        int UserGuess;
        std::cout << "Guess the sum of two dice (2 to 12), or enter 0 to quit: ";
        std::cin >> UserGuess;

        if (UserGuess == 0)
        {
            std::cout << "You chose to quit the game." << std::endl;
            break;
        }

        int dice1 = rollDice();
        int dice2 = rollDice();
        int diceSum = dice1 + dice2;

        std::cout << "Dice 1 rolled: " << dice1 << std::endl;
        std::cout << "Dice 2 rolled: " << dice2 << std::endl;
        std::cout << "Sum of two dice: " << diceSum << std::endl;

        if (UserGuess == diceSum)
        {
            c.coins += c.bet * 2;
            std::cout << "Congratulations! You won " << c.bet * 2 << " coins." << std::endl;
        }
        else if (UserGuess == diceSum - 1 || UserGuess == diceSum + 1)
        {
            c.coins += c.bet * 0.5;
            std::cout << "Congratulations! You won " << c.bet * 0.5 << " coins." << std::endl;
        }
        else
        {
            c.coins -= c.bet;
            std::cout << "Sorry! You lost " << c.bet << " coins." << std::endl;
        }
        std::cout << std::endl;
    }

    if (c.coins <= 0) 
    {
        std::cout << "You are out of coins. Game over." << std::endl;
        std::cout << std::endl;
    }
}

int SlotGenerator()
{
    return (rand() % 7) + 1;
}

void SlotMachine()
{
    std::cout << "Welcome to the Slot Machine!" << std::endl;
    while (c.coins > 0)
    {
        std::cout << "Enter the amount of coins you want to bet (Enter 0 to quit): ";
        std::cin >> c.bet;

        if (c.bet == 0)
        {
            std::cout << "You chose to quit the Slot Machine." << std::endl;
            break;
        }
        else if (c.bet < 0 || c.bet > c.coins)
        {
            std::cout << "Invalid bet. Please enter a valid bet" << std::endl;
            continue;
        }
        int slot1 = SlotGenerator();
        int slot2 = SlotGenerator();
        int slot3 = SlotGenerator();

        std::cout << "The slots you rolled are: " << std::endl;
        std::cout << "Slots: " << "|" << slot1 << "|" << slot2 << "|" << slot3 << "|" << std::endl;

        if (slot1 == slot2 && slot2 == slot3)
        {
            c.coins += c.bet * 7;
            std::cout << "Congratulations! You won " << c.bet * 7 << " coins" << std::endl;
        }
        else
        {
            c.coins -= c.bet;
            std::cout << "Sorry you lost " << c.bet << " coins \n" << std::endl;
        }
        std::cout << std::endl;
    }

    if (c.coins <= 0) 
    {
        std::cout << "You are out of coins. Game over." << std::endl;
        std::cout << std::endl;
    }
}

int RollRoulette()
{
    srand(time(0));
    return (rand() % 36) + 1;
}

void RouletteBets()
{
    int BetType;
    std::cin >> BetType;

    int RouletteNumber = RollRoulette();
    switch (BetType)
    {
    case 1:
        int NumberBet;
        std::cout << "Enter the number you want to bet on ranging from 1 to 36: " << std::endl;
        std::cin >> NumberBet;
        if (NumberBet == RouletteNumber)
        {
            c.coins += c.bet * 36;
            std::cout << "Congratulations! You won " << c.bet * 36 << " coins" << std::endl;
        }
        else
        {
            c.coins -= c.bet;
            std::cout << "Sorry you lost " << c.bet << " coins" << std::endl;
        }
        break;

    case 2:
        std::cout << "Enter 1 to bet on Odd or 2 to bet on Even" << std::endl;
        int OddEvenBet;
        std::cin >> OddEvenBet;

        if ((RouletteNumber % 2 == 1 && OddEvenBet == 1) || (RouletteNumber % 2 == 0 && OddEvenBet == 2))
        {
            c.coins += c.bet * 2;
            std::cout << "Congratulations! You won " << c.bet * 2 << " coins" << std::endl;
        }
        else
        {
            c.coins -= c.bet;
            std::cout << "Sorry you lost " << c.bet << " coins" << std::endl;
        }
        break;

    case 3:
        std::cout << "Enter 1 to bet on Red or enter 2 to bet on Black" << std::endl;
        int ColorBet;
        std::cin >> ColorBet;

        if ((RouletteNumber % 2 == 1 && ColorBet == 1) || (RouletteNumber % 2 == 0 && ColorBet == 2)) //red odd black even
        {
            c.coins += c.bet * 2;
            std::cout << "Congratulations! You won " << c.bet * 2 << " coins" << std::endl;
        }
        else
        {
            c.coins -= c.bet;
            std::cout << "Sorry you lost " << c.bet << " coins" << std::endl;
        }
        break;

    default:
        std::cout << "Invalid option. Please enter a valid option." << std::endl;
        break;
    }
    std::cout << "Roulette Number: " << RouletteNumber << std::endl;
    std::cout << std::endl;
}

void Roulette()
{
    std::cout << "Welcome to Roulette" << std::endl;
    while (c.coins > 0)
    {
        std::cout << "Enter the amount of coins you want to bet (Enter 0 to quit): ";
        std::cin >> c.bet;
        if (c.bet == 0)
        {
            std::cout << "You chose to quit the Roulette." << std::endl;
            break;
        }
        else if (c.bet < 0 || c.bet > c.coins)
        {
            std::cout << "Invalid bet. Please enter a valid bet" << std::endl;
            continue;
        }
        std::cout << "Choose your bet type: " << std::endl;
        std::cout << "1. Bet on a specific number ranging 1 to 36 " << std::endl;
        std::cout << "2. Bet on odd/even" << std::endl;
        std::cout << "3. Bet on red/black" << std::endl;
        std::cout << "Enter 1/2/3 to select the type of bet. " << std::endl;
        RouletteBets();
    }
}

void ShowCoins()
{
    std::cout << "you have " << c.coins << " coins left" << std::endl;
}

void DisplayOptions()
{
    std::cout << "Welcome to the casino." << std::endl;
    while (true)
    {
        std::cout << "Enter 1 to play dice game" << std::endl;
        std::cout << "Enter 2 to play Slot Machine" << std::endl;
        std::cout << "Enter 3 to play Roulette" << std::endl;
        std::cout << "Enter 4 to buy coins" << std::endl;
        std::cout << "Enter 5 to get coin balance" << std::endl;
        std::cout << "Enter 6 to exit" << std::endl;

        int option;
        std::cin >> option;

        switch (option)
        {
        case 1:
            dicegame();
            break;
        case 2:
            SlotMachine();
            break;
        case 3:
            Roulette();
            break;
        case 4:
            userinput();
            break;
        case 5:
            ShowCoins();
            break;
        case 6:
            std::cout << "Thank you for playing at the casino. Goodbye!" << std::endl;
            return;
        default:
            std::cout << "Invalid option. Please enter a valid option." << std::endl;
            break;
        }
        std::cout << std::endl;
    }
}

int main()
{
    DisplayOptions();
    return 0;
}

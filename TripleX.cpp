#include <iostream>
#include <stdio.h>

bool PlayGame(int Difficulty)
{
    std::cout << " you are a secret agent trying to break into a server \n";
    std::cout << " you need to enter the correct code to continue... \n";
    std::cout << "Current level :" << Difficulty << "\n";
    // declare 3 codes
    int CodeA, CodeB, CodeC;
    // random get 3 codes
    CodeA = rand() % (Difficulty + 1) + 1;
    CodeB = rand() % (Difficulty + 1) + 1;
    CodeC = rand() % (Difficulty + 1) + 1;
    // decalre 3 guesses
    int GuessA, GuessB, GuessC;

    // declare product and sum for all 3 codes
    int CodeProduct = CodeA * CodeB * CodeC;
    int CodeSum = CodeA + CodeB + CodeC;
    
    std::cout << "3 codes add up to :" << CodeSum << "\n";
    std::cout << "3 codes mutiply to :" << CodeProduct << "\n";

    // get input of 3 codes
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
    std::cout << std::endl;

    int GuessProduct = GuessA * GuessB * GuessC;
    int GuessSum = GuessA + GuessB + GuessC;
    // check if codes add up
    if (CodeProduct == GuessProduct && CodeSum == GuessSum)
    {
        std::cout << "you have successfully broken into the server!" << std::endl
                  << std::endl;
        return true;
    }
    else
    {
        std::cout << "you lose!";
        return false;
    }
}

int main()
{   
    int Difficulty =1;
    int MaxDiffculty= 10;
    while (Difficulty<=MaxDiffculty)
    {
        bool bLevelComplete = PlayGame(Difficulty);
        std::cin.clear();
        std::cin.ignore();
        if (bLevelComplete)
        {
            // increment difficulty
            ++Difficulty;
        }
        else
        {
            return 0;
        }
    }

    return 0;
}
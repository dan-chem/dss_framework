#include "main.h"

/* Initiate global variables */
int userInput1;

void printHeader()
{
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Welcome to DSS Framework Version " << VERSION << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
}

void printChoice()
{
    std::cout << "" << std::endl;
    std::cout << "Following options are available at the moment: " << std::endl;
    std::cout << "(1) Gaussian file processing" << std::endl;
    std::cout << "(2) Orca file processing" << std::endl;
    std::cout << "(3) Gamess file processing" << std::endl;
    std::cout << "(4) Gromacs file processing" << std::endl;
    std::cout << "Please choose an option: ";
    std::cin >> userInput1;

    if(userInput1 == 1 || userInput1 == 2 || userInput1 == 3 || userInput1 == 4)
    {
        D(std::cout << "Userinput seems to be OK, continue..." << std::endl;)
    }
    else
    {
        std::cout << "There is an error with your Input, check that!" << std::endl;
        exit(1);
    }
}

void checkChoice()
{
    switch (userInput1)
    {
    case 1:
        std::cout << "You chose option 1: Gaussian file processing. That's a good choice!" << std::endl;
        std::cout << "--------------------------------------------------------------------" << std::endl;
        printGaussianChoice();
        break;

    case 2:
        std::cout << "You chose option 2: Orca file processing. That's a good choice!" << std::endl;
        break;

    case 3:
        std::cout << "You chose option 3: Gamess file processing. That's a good choice!" << std::endl;
        break;

    case 4:
        cout << "You chose option 4: Gromacs file processing. That's a good choice!" << endl;
        break;
    
    default:
        std::cout << "Something went very wrong with your choice, please inform the developer" << std::endl;
        exit(1);
    }
}

#include "main.h"

int userInput1;

void printHeader()
{
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "----- Welcome to DSS Framework Version " << VERSION << " -----" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
}

void printChoice()
{
    cout << "" << endl;
    cout << "Following options are available at the moment: " << endl;
    cout << "    (1) Gaussian file processing" << endl;
    cout << "    (2) Orca file processing" << endl;
    cout << "    (3) Gamess file processing" << endl;
    cout << "    (4) Gromacs file processing" << endl;
    cout << "" << endl;
    cout << "Please choose an option: ";
    cin >> userInput1;
    cout << "" << endl;

    if(userInput1 == 1 || userInput1 == 2 || userInput1 == 3 || userInput1 == 4)
    {
        D(cout << "Userinput seems to be OK, continue..." << endl;)
    }
    else
    {
        cerr << "ERROR: There is something wrong with your Input, check that and try again!" << endl;
        exit(1);
    }
}

void checkChoice()
{
    switch (userInput1)
    {
    case 1:
        cout << "---------------------------------------------------------------------------" << endl;
        cout << "--- You chose option 1: Gaussian file processing. That's a good choice! ---" << endl;
        cout << "---------------------------------------------------------------------------" << endl;
        cout << "" << endl;
        printGaussianChoice();
        break;

    case 2:
        cout << "---------------------------------------------------------------------------" << endl;
        cout << "----- You chose option 2: Orca file processing. That's a good choice! -----" << endl;
        cout << "---------------------------------------------------------------------------" << endl;
        cout << "" << endl;
        break;

    case 3:
        cout << "---------------------------------------------------------------------------" << endl;
        cout << "---- You chose option 3: Gamess file processing. That's a good choice! ----" << endl;
        cout << "---------------------------------------------------------------------------" << endl;
        cout << "" << endl;
        break;

    case 4:
        cout << "---------------------------------------------------------------------------" << endl;
        cout << "--- You chose option 4:  Gromacs file processing. That's a good choice! ---" << endl;
        cout << "---------------------------------------------------------------------------" << endl;
        cout << "" << endl;
        printGromacsChoice();
        break;
    
    default:
        std::cout << "ERROR: Something went very wrong with your choice, please inform the" << std::endl;
        cout << "developer! " << endl;
        exit(1);
    }
}

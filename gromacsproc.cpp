#include "main.h"

void printGromacsChoice()
{
    static int userInputGromacs1;
    static string userInputFilenameXVG;

    cout << "Here are your possible options for Gromacs file processing: " << endl;
    cout << "(1) Calculate coordination number by numerical integration of RDF" << endl;
    cout << "" << endl;
    cout << "Please choose an option (pretty funny, since it's only one at the moment :D): ";
    cin >> userInputGromacs1;
    cout << "--------------------------------------------------------------------" << endl;

    if(userInputGromacs1 == 1 /* || for further options */ )
    {
        switch (userInputGromacs1)
        {
        case 1:
            cout << "You asked to calculate the coordination number from an RDF by numerical integration, so let's start..." << endl;
            cout << "Please provide me the filename of the XVG output file (including the extension): ";
            cin >> userInputFilenameXVG;
            /*readInputFile(userInputFilenameXVG);
            checkCalcType();
            checkGeomConvergence();*/
            break;
        
        default:
            break;
        }
    }
    else
    {
        cout << "You didn't provide a meaningful choice... Exiting..." << endl;
        exit(1);
    }
}
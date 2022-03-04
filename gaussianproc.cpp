#include "main.h"

/* Initiate global variables */
int userInput2;
int numLines;
string userInputFilename;
vector<string> extractedLine{};

void printGaussianChoice()
{
    cout << "Here are your possible options for Gaussian output file processing: " << endl;
    cout << "(1) Check geometry optimization for convergence" << endl;
    cout << "(2) Check frequency analysis for imaginary frequencies" << endl;
    cout << "" << endl;
    cout << "Here are your possible options for Gaussian input creation and parsing: " << endl;
    cout << "(100) Create new Gaussian input w/o xyz-matrix" << endl;
    cout << "(101) Parse existing Gaussian input file for possible errors and critical combinations" << endl;
    cout << "" << endl;
    cout << "Please choose an option: ";
    cin >> userInput2;
    cout << "--------------------------------------------------------------------" << endl;

    // Switch through all user inputs -> find a better solution for that!

    if(userInput2 == 1 || userInput2 == 2 || userInput2 == 100 || userInput2 == 101)
    {
        switch (userInput2)
        {
        case 1:
            cout << "You asked to check a geometry optimization for convergence, so let's start..." << endl;
            cout << "Please provide me the filename of the Gaussian output file (including the extension): ";
            cin >> userInputFilename;
            readInputFile(userInputFilename);
            checkCalcType();
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

void readInputFile(string userInputFilename)
{
    static string line;
    ifstream inputFile(userInputFilename);
    if(inputFile.is_open())
    {
        while(getline(inputFile, line))
        {
            extractedLine.push_back(line);
            ++numLines;
        }
        inputFile.close();
        D(cout << "I read " << numLines << " number of lines in total." << endl;)
    }
    else
    {
        cout << "Couldn't read in the given file... Exiting..." << endl;
        exit(1);
    }
}

void checkCalcType()
{
    static string lineGaussianKeywords;

    for(int j = 0; j < numLines; j++)
    {
        if(extractedLine[j].find("#") != string::npos)
        {
            lineGaussianKeywords = extractedLine[j];
            D(cout << "Found line with Gaussian Keywords: " << lineGaussianKeywords << endl;)
            break;
        }
    }

    cout << "Test" << endl;
}
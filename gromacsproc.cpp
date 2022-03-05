#include "main.h"
#include "GromacsProc.h"

string userInputFilenameXVG;

void printGromacsChoice()
{
    static int userInputGromacs1;

    GromacsProc proc1;

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
            proc1.readGromacsXVG(userInputFilenameXVG);
            proc1.cutGromacsLineVector();/*
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

void GromacsProc::readGromacsXVG(const string userInputFilenameXVG)
{
    string line;

    ifstream inputFile(userInputFilenameXVG);
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

void GromacsProc::cutGromacsLineVector()
{
    int cutLineCounter;
    D(static int newNumLines;)

    for(int j = 0; j < numLines; j++)
    {
        if(extractedLine[j].find("#") != string::npos)
        {
            cutLineCounter++;
            D(cout << "Found new line starting with #, total lines to cut so far: " << cutLineCounter << endl;)
        }
        if(extractedLine[j].find("@") != string::npos)
        {
            cutLineCounter++;
            D(cout << "Found new line starting with @, total lines to cut so far: " << cutLineCounter << endl;)
        }        
    }

    extractedLine.erase(extractedLine.begin(),extractedLine.begin() + cutLineCounter);
    D(cout << "Vector cut successful, this is what i got: " << endl;)
    D(newNumLines = numLines - cutLineCounter;)
    D(for(int k = 0; k < newNumLines; k++){cout << extractedLine[k] << endl;})
}

void transferVector()
{
    for(int j = 0; j < numLines; j++)
    {
       
    }    
}
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
            proc1.cutGromacsLineVector();
            proc1.transferVector();
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

    D(cout << "Vector cut successful, this is what i got (first 20 lines): " << endl;)
    D(for(int k = 0; k < 20; k++){cout << extractedLine[k] << endl;})
}

void GromacsProc::transferVector()
{
    D(cout << "CAREFUL! The length of the array for the Integration is predefined at " << _INTEGRATOR_LENGTH << " values! Change the macro _INTEGRATOR_LENGTH if needed!" << endl;)
    D(cout << "For testing purposes, this is substring 1 and 2 of the 25th line: " << extractedLine[25].substr(6,5) << " " << extractedLine[25].substr(15,5) << endl;)

    for(int j = 0; j < _INTEGRATOR_LENGTH; j++)
    {
       integrator[j][0] = {stod(extractedLine[j].substr(6,5))}; // Crazy array declaration -> substring is converted to double
       integrator[j][1] = {stod(extractedLine[j].substr(15,5))};
    }
    
    D(cout << "To give an example of stored array, here is element [25][0]: " << integrator[25][0] << endl;)
    D(cout << "And here is element [25][1]: " << integrator[25][1] << endl;)
}

int GromacsProc::numericalIntegration()
{
    
}
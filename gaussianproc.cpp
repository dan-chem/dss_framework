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
            checkGeomConvergence();
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
    // Return Value 1: Calculation is a geometry optimization
    // Return Value 2: Calculation is a freqency analysis
    // Return Value 3: Calculation is a combination of both
    // Return Value 4: 
    
    static string lineGaussianKeywords;
//    static bool gaussianOpt = false;
//    static bool gaussianFreq = false;
//    static bool gaussianNBO = false;

    for(int j = 0; j < numLines; j++)
    {
        if(extractedLine[j].find("#") != string::npos)
        {
            lineGaussianKeywords = extractedLine[j];
            D(cout << "Found line with Gaussian Keywords: " << lineGaussianKeywords << endl;)
            break;
        }
    }

    //There's probably a more elegant way for doing that! -> Find it

    if(lineGaussianKeywords.find("opt") != string::npos || lineGaussianKeywords.find("OPT") != string::npos)
    {
//        gaussianOpt = true;
        D(cout << "You performed a geometry optimization!" << endl;)
    }

    if(lineGaussianKeywords.find("freq") != string::npos || lineGaussianKeywords.find("FREQ") != string::npos)
    {
//        gaussianFreq = true;
        D(cout << "You performed a frequency calculation!" << endl;)
    }

/*    if(lineGaussianKeywords.find("nbo") != string::npos || lineGaussianKeywords.find("NBO") != string::npos)
    {
        gaussianNBO = true;
        D(cout << "You performed a NBO population analysis!" << endl;)
    }

    if(gaussianOpt == true && gaussianFreq == false)
    {
        return 1;
    }
    else if(gaussianOpt == false && gaussianFreq == true)
    {
        return 2;
    }
    else if(gaussianOpt == true && gaussianFreq == true)
    {
        return 3;
    }
    else
    {
        exit(1);
    }*/
}

void checkGeomConvergence()
{
    static string maxForceLine;
    static string rmsForceLine;
    static string maxDisplacementLine;
    static string rmsDisplacementLine;

    static bool maxForceConv;
    static bool rmsForceConv;
    static bool maxDisplacementConv;
    static bool rmsDisplacementConv;

    for(int j = 0; j < numLines; j++)
    {
        if(extractedLine[j].find("Item") != string::npos)
        {
            maxForceLine = extractedLine[j+1];
            D(cout << "Found line with Gaussian Maximum Force information: " << maxForceLine << endl;)
            rmsForceLine = extractedLine[j+2];
            D(cout << "Found line with Gaussian RMS Force information: " << maxForceLine << endl;)
            maxDisplacementLine = extractedLine[j+3];
            D(cout << "Found line with Gaussian Maximum Displacement information: " << maxForceLine << endl;)
            rmsDisplacementLine = extractedLine[j+4];
            D(cout << "Found line with Gaussian RMS Displacement information: " << maxForceLine << endl;)
        }        
    }

    if(maxForceLine.find("YES") != string::npos)
    {
        maxForceConv = true;
    }
    if(rmsForceLine.find("YES") != string::npos)
    {
        rmsForceConv = true;
    }
    if(maxDisplacementLine.find("YES") != string::npos)
    {
        maxDisplacementConv = true;
    }
    if(rmsDisplacementLine.find("YES") != string::npos)
    {
        rmsDisplacementConv = true;
    }

    if(maxForceConv == true && rmsForceConv == true && maxDisplacementConv == true && rmsDisplacementConv == true)
    {
        cout << "Geometry Optimization looks fine, everything is converged!" << endl;
    }
    else
    {
        cout << "Oh no! Something did not converge, check that!" << endl;
    }
}
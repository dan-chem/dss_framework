#include "GaussianProc.h"

string userInputFilenameLOG;


void printGaussianChoice()
{
    int userInputGaussian1;

    GaussianProc proc1;

    cout << "Here are your possible options for Gaussian output file processing: " << endl;
    cout << "    ( 1 ) Check geometry optimization for convergence" << endl;
    cout << "    ( 2 ) Check frequency analysis for imaginary frequencies" << endl;
    cout << "" << endl;
    cout << "Here are your possible options for Gaussian input creation and parsing: " << endl;
    cout << "    (100) Create new Gaussian input w/o xyz-matrix" << endl;
    cout << "    (101) Parse existing Gaussian input file for possible errors and" << endl;
    cout << "          critical combintations" << endl;
    cout << "" << endl;
    cout << "Here are miscellaneous options: " << endl;
    cout << "    (999) Exit Framework" << endl;
    cout << "" << endl;
    cout << "Please choose an option: ";
    cin >> userInputGaussian1;
    cout << "" << endl;
    cout << "---------------------------------------------------------------------------" << endl;

    // Switch through all user inputs -> find a better solution for that!

    if(userInputGaussian1 == 1 || userInputGaussian1 == 2 || userInputGaussian1 == 100 || userInputGaussian1 == 101 || userInputGaussian1 == 999)
    {
        switch (userInputGaussian1)
        {
        case 1:
            cout << "You asked to check a geometry optimization for convergence, so let's" << endl;
            cout << "start..." << endl;
            cout << "Please provide me the filename of the Gaussian output file" << endl;
            cout << "(including the extension): ";
            cin >> userInputFilenameLOG;
            proc1.readInputFile(userInputFilenameLOG);

            proc1.checkCalcType();

            proc1.checkGeomConvergence();
            break;
        
        case 999:
            exit(0);

        default:
            break;
        }
    }
    else
    {
        cerr << "ERROR: You didn't provide a meaningful choice... Exiting..." << endl;
        exit(1);
    }
    
}

void GaussianProc::readInputFile(string userInputFilenameLOG)
{
    static string line;

    ifstream inputFile(userInputFilenameLOG);
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
        cerr << "ERROR: Couldn't read in the given file... Exiting..." << endl;
        exit(1);
    }
}

void GaussianProc::checkCalcType()
{ 
    static string lineGaussianKeywords;
    static bool gaussianOpt = false;
    static bool gaussianFreq = false;
    static bool gaussianNBO = false;

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
        gaussianOpt = true;
        D(cout << "You performed a geometry optimization!" << endl;)
    }

    if(lineGaussianKeywords.find("freq") != string::npos || lineGaussianKeywords.find("FREQ") != string::npos)
    {
        gaussianFreq = true;
        D(cout << "You performed a frequency calculation!" << endl;)
    }

    if(lineGaussianKeywords.find("nbo7") != string::npos || lineGaussianKeywords.find("NBO7") != string::npos)
    {
        gaussianNBO = true;
        D(cout << "You performed a NBO7 population analysis!" << endl;)
    }

    if(gaussianOpt == true && gaussianFreq == false)
    {
        calculationType = 1;
    }
    else if(gaussianOpt == false && gaussianFreq == true)
    {
        calculationType = 2;
    }
    else if(gaussianOpt == true && gaussianFreq == true)
    {
        calculationType = 3;
    }
    else if(gaussianNBO == true)
    {
        calculationType = 4;
    }
    else
    {
        exit(1);
    }
}

void GaussianProc::checkGeomConvergence()
{
    static string maxForceLine;
    static string rmsForceLine;
    static string maxDisplacementLine;
    static string rmsDisplacementLine;

    static bool maxForceConv;
    static bool rmsForceConv;
    static bool maxDisplacementConv;
    static bool rmsDisplacementConv;

    if(calculationType == 2 || calculationType == 4)
    {
        cerr << "ERROR: You didn't perform a geometry optimization in this file! Exiting!" << endl;
        exit(1);
    }

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
        cout << endl;
        cout << "---------------------------------------------------------------------------" << endl;
        cout << "------- Geometry Optimization looks fine,  everything is converged! -------" << endl;
        cout << "---------------------------------------------------------------------------" << endl;
        cout << endl;
        exit(0);
    }
    else
    {
        cout << endl;
        cout << "---------------------------------------------------------------------------" << endl;
        cout << "------------- Oh no!  Something did not converge, check that! -------------" << endl;
        cout << "---------------------------------------------------------------------------" << endl;
        cout << endl;
        exit(0);
    }
}
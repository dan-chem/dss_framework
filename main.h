using namespace std;

/* Define global includes */
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

/* Define Macros */

#define VERSION "0.3 alpha"
#ifdef DEBUG
    #define D(x) x
#else
    #define D(x)
#endif

/* Define Functions in standardmsg.cpp */

void printHeader();
void printChoice();
void checkChoice();

/* Define functions in gaussianproc.cpp */

void printGaussianChoice();
extern int userInput2;

void readInputFile(string userInputFilename);
extern string userInputFilename;

extern vector<string> extractedLine;
extern int numLines;

void checkCalcType();

void checkGeomConvergence();

/* Define functions in gromacsproc.cpp */

void printGromacsChoice();
void transferVector();

/* Define global variables */

extern int userInput1;


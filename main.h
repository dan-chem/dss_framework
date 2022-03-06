using namespace std;

/* Define global includes */
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

/* Define Macros */

#define VERSION "0.4 alpha"
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

/* Define functions in gromacsproc.cpp */

void printGromacsChoice();

/* Define global variables */



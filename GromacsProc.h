#include "main.h"

#ifndef _INTEGRATOR_LENGTH
    #define _INTEGRATOR_LENGTH 1189  // Check, if 1189 is standard length of RDF XVG!
#endif
#ifndef _INTEGRATOR_STEPSIZE
    #define _INTEGRATOR_STEPSIZE 0.002 // Check, if standard stepsize in RDF XVG is correct!
#endif

#define PI 3.141592653589

#ifndef RHO
    #define RHO 0.936 // Assume that density for the system is 1, implement user input later!
#endif

class GromacsProc
{
    public:

        void readGromacsXVG(const string);
        void cutGromacsLineVector();
        void transferVector();
        void getCoordinationNumber();

    private:
        // First declared in readGromacsXVG(const string)
        static string line;
        vector<string> extractedLine;
        int numLines;

        // First declared in cutGromacsLineVector()
        static int cutLineCounter;

        // First declared in transferVector()
        double integrator[_INTEGRATOR_LENGTH][2];

        // First declared in numericalIntegration()
        double integrationUpperLimit;
        double totalSum;
        double totalSumCorr;
        double integrand;
        double mixedSum;
        int stepCounter;
};
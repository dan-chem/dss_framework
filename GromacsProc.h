#include "main.h"

#ifndef _INTEGRATOR_LENGTH
    #define _INTEGRATOR_LENGTH 1189  // Check, if 1189 is standard length of RDF XVG!
#endif

class GromacsProc
{
    public:

        void readGromacsXVG(const string);
        void cutGromacsLineVector();
        void transferVector();
        int numericalIntegration();

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
};
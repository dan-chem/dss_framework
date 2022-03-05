#include "main.h"

class GromacsProc
{
    public:

        void readGromacsXVG(const string);
        void cutGromacsLineVector();

    private:
        // First declared in readGromacsXVG(const string)
        static string line;
        vector<string> extractedLine;
        int numLines;

        // First declared in cutGromacsLineVector()
        static int cutLineCounter;
};
#include "main.h"

class GaussianProc
{
    public:

        void readInputFile(const string);
        void checkCalcType();
        void checkGeomConvergence();

    private:

        int numLines;
        vector<string> extractedLine{};
        

};
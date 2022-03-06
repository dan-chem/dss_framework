#include "main.h"

class GaussianProc
{
    public:

        void readInputFile(const string);

        int calculationType; // 1 = opt, 2 = freq, 3 = opt+freq, 4 = nbo7
        void checkCalcType();
        
        void checkGeomConvergence();

    private:



        int numLines;
        vector<string> extractedLine{};

        

};
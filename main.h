/* Define Macros */

#define VERSION "0.1 alpha"
#ifdef DEBUG
    #define D(x) x
#else
    #define D(x)
#endif

/* Define Functions */

void printHeader();
void printChoice();
void checkChoice();

/* Define global variables */

extern int userInput1;
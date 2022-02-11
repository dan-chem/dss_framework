#include "main.h"

int main()
{
    D(std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
        std::cout << "CAUTION! DEBUG MODE IS ACTIVE! THIS CAN CAUSE HEAVY I/O!" << std::endl;
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;)
    printHeader();
    printChoice();
    checkChoice();
    return 0;
}
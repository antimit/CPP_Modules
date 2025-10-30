#include "Harl.hpp"
#include <iostream>

int main(int ac, char** av) {
    Harl harl;

   
    if (ac == 2) {
        harl.complain(av[1]);
        return 0;
    }

    const char* tests[] = { "DEBUG", "INFO", "WARNING", "ERROR", "BOGUS" };
    for (int i = 0; i < 5; ++i) {
        std::cout << "========== " << tests[i] << " ==========\n";
        harl.complain(tests[i]);
        std::cout << std::endl;
    }
    return 0;
}

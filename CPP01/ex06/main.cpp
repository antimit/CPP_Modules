#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage: ./harlFilter <level>" << std::endl;
        return 1;
    }

    std::string level = av[1];
    Harl harl;

    int idx = -1;
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    for (int i = 0; i < 4; ++i) {
        if (level == levels[i]) {
            idx = i;
            break;
        }
    }

    switch (idx) {
        case 0:
            harl.debug();
        case 1:
            harl.info();
        case 2:
            harl.warning();
        case 3:
            harl.error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }

    return 0;
}

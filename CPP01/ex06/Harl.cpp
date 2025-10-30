#include "Harl.hpp"
#include <iostream>

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug() const {
    std::cout
        << "[ DEBUG ]\n"
        << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. "
        << "I really do!"
        << std::endl;
}

void Harl::info() const {
    std::cout
        << "[ INFO ]\n"
        << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! "
        << "If you did, I wouldn’t be asking for more!"
        << std::endl;
}

void Harl::warning() const {
    std::cout
        << "[ WARNING ]\n"
        << "I think I deserve to have some extra bacon for free. I’ve been coming for years, "
        << "whereas you started working here just last month."
        << std::endl;
}

void Harl::error() const {
    std::cout
        << "[ ERROR ]\n"
        << "This is unacceptable! I want to speak to the manager now."
        << std::endl;
}

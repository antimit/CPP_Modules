#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <cctype>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <iomanip>
#include <cstdio>
#include "Contact.hpp"

class PhoneBook
{
    public:
    PhoneBook();
    ~PhoneBook();

    void ADD();
    void SEARCH();    
    private: 
    Contact contacts [8];
    const int max_contacts;
    int	current_nb;
    int	nb_contacts;

};

#endif
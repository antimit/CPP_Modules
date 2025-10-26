#include <string>
#include <vector>
#include <iostream>
#include "Contact.hpp"

class PhoneBook{

   
    private: 
    static std::vector<Contact> contacts;

    public:
    void ADD();
    void SEARCH();
    void EXIT();
    

};
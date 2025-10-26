#include "PhoneBook.hpp"

void PhoneBook::ADD()
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string secret;

    system("clear");
    std::cout<<"Write a first name: ";
    std:getline(std::cin, first_name);
    system("clear");

    std::cout<<"Write a last_name: ";
    std::getline(std::cin, last_name);
    system("clear");

    std::cout<<"Write a nickname: ";
    std::getline(std::cin, nickname);
    system("clear");
    
    std::cout<<"Write a secret: ";
    std::getline(std::cin, secret);
    system("clear");


    Contact new_contact (first_name, last_name, nickname,secret);

    contacts.push_back(new_contact);   
}
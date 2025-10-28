#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string line;

    system("clear");
    std::cout << "Welcome to contact manager" << std::endl;
    while(1)
    {
        std::cout << "Type ADD, SEARCH or EXIT"<<std::endl;
        if(!std::getline(std::cin, line))
        {
            std::cout << "\nEOF detected. Goodbye !" << std::endl;
            break;   
        }
        
        if(!line.compare("ADD"))
            phoneBook.ADD();
        
        else if(!line.compare("SEARCH"))
            phoneBook.SEARCH();
        else if (!line.compare("EXIT"))
        {
            std::cout<<"Goodbye !" << std::endl;
            break;
        }
        else
        {
            std::cout<<"You typed the wrong command"<<std::endl;
            continue;
        }
        system("clear");
    }
    sleep(1);
   
    return 0;
}
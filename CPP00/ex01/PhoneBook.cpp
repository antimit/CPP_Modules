#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): max_contacts(8), current_nb(0),nb_contacts(0)
{
   
}

PhoneBook::~PhoneBook()
{

}

void PhoneBook::ADD()
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone;
    std::string secret;

    system("clear");
    std::cout<<"Write a first name: ";
    std::getline(std::cin, first_name);
    system("clear");

    std::cout<<"Write a last_name: ";
    std::getline(std::cin, last_name);
    system("clear");

    std::cout<<"Write a nickname: ";
    std::getline(std::cin, nickname);
    system("clear");

     std::cout<<"Write a phone: ";
    std::getline(std::cin, phone);
    system("clear");
    
    std::cout<<"Write a secret: ";
    std::getline(std::cin, secret);
    system("clear");

    if (first_name.empty() || last_name.empty() || nickname.empty() ||
    phone.empty() || secret.empty()) 
    {
        std::cout << "A contact cannot have empty fields! Abort..." << std::endl;
        sleep(1);
        return;
    }

    Contact new_contact (first_name, last_name, nickname, phone, secret);
    contacts[current_nb] = new_contact;   

    this->current_nb = (this->current_nb+1)%max_contacts;
    if(nb_contacts < 8)
        nb_contacts++;
}

void PhoneBook::SEARCH()
{
    int i = 0;
    std::string FirstName;
    std::string LastName;
    std::string Nickname;
    std::string ret;
    int index;

    system("clear");
    if(this->nb_contacts==0)
    {
        std::cout<<"No contact available ! Abort..."<<std::endl; sleep(1); return;
    }

    std::cout<<std::setw(10) << "Index" << "|";
    std::cout<<std::setw(10) << "Firstname" << "|";
    std::cout<<std::setw(10) << "Lastname" << "|";
    std::cout<<std::setw(10) << "Nickname" << "|" <<std::endl;
    while(i < nb_contacts)
    {
        std::cout<< std::setw(10) << i << "|";
        FirstName = this->contacts[i].get_first_name();
        LastName = this->contacts[i].get_last_name();
        Nickname = this->contacts[i].get_nickname();

        if(FirstName.length() > 10)
            FirstName = FirstName.substr(0,9) + ".";
        
        if(LastName.length() > 10)
            LastName = LastName.substr(0,9) + ".";
        
        if(Nickname.length() > 10)
            Nickname = Nickname.substr(0,9) + ".";
        
        std::cout << std::setw(10) << FirstName << "|";
        std::cout << std::setw(10) << LastName << "|";
        std::cout << std::setw(10) << Nickname << "|"<<std::endl;
        i++;
    }   
        
        std::cout << std::endl << "Type a contact's index to obtain personal information : ";
        std::getline(std::cin, ret);

        if (ret.empty() || ret.find_first_not_of("0123456789") != std::string::npos)
        {
            std::cout << "Enter a valid digit ! Abort..." << std::endl; sleep(1); return;
        }

        index = atoi(ret.c_str());
        
        if(index < 0 || index >7 || index >= this->nb_contacts)
        {
            std::cout << "No contact found ! Abort ..." << std::endl; sleep(1); return;
        }

        std::cout << "First Name : " << this->contacts[index].get_first_name()<< std::endl;
        std::cout << "Last Name : " << this->contacts[index].get_last_name()<< std::endl;
        std::cout << "Nickname : " << this->contacts[index].get_nickname()<< std::endl;
        std::cout << "Phone number : " << this->contacts[index].get_phone()<< std::endl;
        std::cout << "Secret : " << this->contacts[index].get_secret()<< std::endl;
        getchar();
        getchar();
    }

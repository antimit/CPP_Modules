#include "Contact.hpp"

std::string Contact::get_first_name() const 
{
    return first_name;
}

std::string Contact::get_last_name() const
{
    return last_name;
}


std::string Contact::get_nickname() const
{
    return nickname;
}

std::string Contact::get_phone() const
{
    return phone;
}

std::string Contact::get_secret() const
{
    return secret;
}



void Contact::set_first_name(std::string first_name)
{
    this->first_name = first_name;
}

void Contact::set_last_name(std::string last_name)
{
    this->last_name = last_name;
}

void Contact::set_nickname(std::string nickname)
{
    this->nickname = nickname;
}

void Contact::set_phone(std::string phone)
{
    this->phone = phone;
}

void Contact::set_secret(std::string secret)
{
    this->secret = secret;
}
  
Contact:: Contact( std::string first_name,
    std::string last_name,
    std::string nickname,
    std::string phone,
    std::string secret)
    {
        this->first_name = first_name;
        this->last_name = last_name;
        this->nickname = nickname;
        this->phone = phone;
        this->secret = secret;
    };
Contact::Contact()
{
    this->first_name = "";
    this->last_name = "";
    this->nickname = "";
    this->phone = "";
    this->secret = "";
}

Contact::~Contact()
{

}


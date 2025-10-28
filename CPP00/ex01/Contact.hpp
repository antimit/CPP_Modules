#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact {

    
    public:
    
    Contact( std::string first_name,
    std::string last_name,
    std::string nickname,
    std::string phone,
    std::string secret);
    Contact();
    ~Contact();

    //getters
    std::string get_first_name()const;
    std::string get_last_name() const;
    std::string get_nickname() const;
    std::string get_phone() const;
    std::string get_secret() const;

    //setters
    void set_first_name(std::string first_name);
    void set_last_name(std::string last_name);
    void set_nickname(std::string nickname);
    void set_phone(std::string phone);
    void set_secret(std::string secret);

    private: 
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone;
    std::string secret;


    
};
#endif
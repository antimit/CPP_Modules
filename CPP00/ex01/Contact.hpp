#include <string>

class Contact {

    
    public:
    
    Contact( std::string first_name,
    std::string last_name,
    std::string nickname,
    std::string secret)
    {
        this->first_name = first_name;
        this->last_name = last_name;
        this->nickname = nickname;
        this->secret = secret;
    }
    //getters
    std::string get_first_name();
    std::string get_last_name();
    std::string get_nickname();
    std::string get_secret();

    //setters
    void set_first_name(std::string index);
    void set_last_name(std::string index);
    void set_nickname(std::string index);
    void set_secret(std::string secret);

    private: 
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string secret;


    
};
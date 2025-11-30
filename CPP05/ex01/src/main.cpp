#include "Bureaucrat.hpp"

int main()
{

   try
   {
        Form form("Important", 1,1);
        Bureaucrat a("John",1);

        a.signForm(form);
        
   }
   catch(const std::exception& e)
   {
    std::cerr << e.what() << '\n';
   }
   
}


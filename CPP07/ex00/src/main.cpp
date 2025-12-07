#include "Whatever.hpp"


// int main()
// {
//     int a = 5;
//     int b = 10;

//     std::cout<<"a before: "<<a<<std::endl;
//     std::cout<<"b before: "<<b<<std::endl;

//     swap<int>(a,b);

//     std::cout<<"a after: "<<a<<std::endl;
//     std::cout<<"b after: "<<b<<std::endl;

//     std::cout<<"Comparison which value is bigger max<int>(a,b): "<<max<int>(a,b)<<std::endl;
//     std::cout<<"Comparison which value is smaller min<int>(a,b): "<<min<int>(a,b)<<std::endl;
// }

int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}
#include <iostream>


int main()
{
    std::cout << "------------------------" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "Program started........!" << std::endl;
    std::cout << "------------------------" << std::endl;

    std::cout << "size of char:\t\t"        << sizeof(char)         << std::endl;
    std::cout << "size of chat16_t:\t"      << sizeof(char16_t)     << std::endl;
    std::cout << "size of char32_t:\t"      << sizeof(char32_t)     << std::endl;
    std::cout << "size of short:\t\t"       << sizeof(short)        << std::endl;
    std::cout << "size of int:\t\t"         << sizeof(int)          << std::endl;
    std::cout << "size of long long:\t"     << sizeof(long long)    << std::endl;
    std::cout << "size of float:\t\t"       << sizeof(float)        << std::endl;
    std::cout << "size of double:\t\t"      << sizeof(double)       << std::endl;
    std::cout << "size of long double:\t"   << sizeof(long double)  << std::endl;
    
    return 0;
}
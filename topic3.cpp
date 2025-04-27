#include<iostream>
#include<string>



int main()
{
    double d = 0;
    std::string s = "asdasd";

    try{

        d = std::stod(s);
    
    }catch(const std::exception& e)
    {
        
    }
    
    std::cout << "d: " << d << std::endl;
    
    return 0;
}
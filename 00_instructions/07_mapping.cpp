#include <iostream>
#include <map>

int main()
{
    std::map<std::string, double> myMap = {
        {"a", 3.5},
        {"b",4.3}
    };

    

    std::cout << "myMap.size: " << myMap.size() << std::endl;
    std::cout << "myMap.begin: " << myMap.at("b") << std::endl;


}
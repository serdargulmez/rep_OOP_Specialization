#include<iostream>
#include<vector>


int main()
{
    std::vector<double> prices;

    for(unsigned int i=1; i<100; ++i)
    {
        prices.push_back(i);
    }

    for(double& p : prices)
    {
        std::cout << p << std::endl;
    }
    
    
    std::cout << prices.size() << std::endl;
      



    return 0;
}
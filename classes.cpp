#include <iostream>

class Square
{
    public:
        unsigned short side_1;
        unsigned short side_2;
   
};

int main()
{
    Square squ_01, squ_02;
    
    squ_01.side_1 = 3;
    squ_01.side_2 = 4;

    squ_02.side_1 = 2;
    squ_02.side_2 = 3;

    std::cout << "squ_01.side_1: " << squ_01.side_1 << std::endl;
    std::cout << "squ_02.side_1: " << squ_02.side_1 << std::endl;   




    return 0;
}
#include <iostream>

class Square
{
    public:
        Square( unsigned short _side_1,
                unsigned short _side_2)
        {
            side_1 = _side_1;
            side_2 = _side_2;
        }

        unsigned short side_1;
        unsigned short side_2;
   
};

int main()
{
    Square squ_01{3,4}, squ_02{2,3};
    
    std::cout << "squ_01.side_1: " << squ_01.side_1 << std::endl;
    std::cout << "squ_02.side_1: " << squ_02.side_1 << std::endl;   

    return 0;
}
#include <iostream>
#include <vector>

class Square
{
    public:
        Square( unsigned short _side_1,
                unsigned short _side_2)
        : side_1(_side_1),
          side_2(_side_2)
        {
        }

        unsigned short side_1;
        unsigned short side_2;
   
};

int main()
{
    // Square squ_01{3,5}, squ_02{4,6};

    std::vector<Square> squares;

    squares.push_back(Square{3,5});
    squares.push_back(Square{4,6});

    
    // std::cout << "squ_01.side_1: " << squares[0].side_1 << std::endl;
    // std::cout << "squ_02.side_1: " << squares[1].side_1 << std::endl;   

    for(Square sq : squares)
    {
      std::cout << "squares side1: " << sq.side_1 << std::endl;
    }



    return 0;
}
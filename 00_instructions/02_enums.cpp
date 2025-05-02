#include <iostream>

enum class OrderBookType
{
    bid,
    ask
};

int main()
{
    std::cout << "--------------------" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "Program began......!" << std::endl;
    std::cout << "--------------------" << std::endl;

    OrderBookType orderType = OrderBookType::ask;
}

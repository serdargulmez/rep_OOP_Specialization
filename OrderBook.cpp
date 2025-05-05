#include "OrderBook.h"
#include <map>

OrderBook::OrderBook(std::string filename)
{
    orders = CSVReader::readCSV(filename);
}
std::vector<std::string> OrderBook::getKnownProducts()
{
    std::vector<std::string> products;
    std::map<std::string,bool> prodMap;

    for(OrderBookEntry &e : orders)
    {
        prodMap[e.product] = true;
    }

    for(auto const &p : prodMap)
    {
        products.push_back(p.first);   
    }

    return products;

}
std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type,
                                        std::string product,
                                        std::string timestamp)
{
    std::vector<OrderBookEntry> orders_sub;
    return orders_sub;

}
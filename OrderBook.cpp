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
    for(OrderBookEntry &e : orders)
    {
        if(e.orderType == type && e.product == product && e.timestamp == timestamp)
        {
            orders_sub.push_back(e);
        }
    }

    return orders_sub;

}

double OrderBook::getHighPrice(std::vector<OrderBookEntry> &orders)
{
    double max = orders[0].price;
    for(OrderBookEntry &e : orders)
    {
        if(e.price > max)
        {
            max = e.price;
        }
    }

    return max;
}

double OrderBook::getLowPrice(std::vector<OrderBookEntry> &orders)
{
    double min = orders[0].price;
    for(OrderBookEntry &e : orders)
    {
        if(e.price < min)
        {
            min = e.price;
        }
    }

    return min;
}

std::string OrderBook::getEarliestTime()
{
    return orders[0].timestamp;
}

std::string OrderBook::getNextTime(std::string timestamp)
{
    std::string next_timestamp = "";
    for(OrderBookEntry &e : orders)
    {
        if(e.timestamp > timestamp)
        {
            next_timestamp = e.timestamp;
            break;
        }
    }

    if(next_timestamp == "")
    {
        next_timestamp = orders[0].timestamp;
    }

    return next_timestamp;

}

/*
    Purpose: To calculate change value as a percentage to identify
             volatile range in prices.
             Transmitter knows price increment and decrement. 
    Definition: Input parameter is orders as a reference.
                Code evaulate the input "orders" parameter to find
                max price and low price by already created
                OrderBook::getHighPrice(orders) and
                OrderBook::getLowPrice(orders) functions in the OrderBook Class.
                And so with percentage calculation increment and
                decrement about prices are sent to the user.

*/
double OrderBook::getChange(std::vector<OrderBookEntry> &orders)
{
    const unsigned short perValue = 100;
    double maxPrice = OrderBook::getHighPrice(orders); // max price is received
    double minPrice = OrderBook::getLowPrice(orders); // min price is received
    double percentage = 0.0;

    if (maxPrice > minPrice)
    {
        // change range is calculated as percentage for increment
        percentage = (( maxPrice / minPrice ) * perValue) - perValue;
    }
    else
    {
        // change range is calculated as percentage for decrement
        percentage = (( minPrice / maxPrice ) * perValue) - perValue;
        percentage *= -1; // for decrement value is showed with a negative number
    }

    return percentage; // percentage is sent
}
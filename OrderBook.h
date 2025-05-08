#pragma once
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <string>
#include <vector>

class OrderBook
{
public:
    /** construct, reading a .csv data file */
    OrderBook(std::string filename);
    /** return vector of all known products in the dataset */
    std::vector<std::string> getKnownProducts();
    /** return vector of Orders according to the sent filters */
    std::vector<OrderBookEntry> getOrders(OrderBookType type,
                                          std::string product,
                                          std::string timestamp);
    /** return the max price according to product */
    static double getHighPrice(std::vector<OrderBookEntry> &orders);
    /** return the min price according to product */
    static double getLowPrice(std::vector<OrderBookEntry> &orders);

    /** returns the earliest time in the orderbook */
    std::string getEarliestTime();
    /** returns the next time after the sent time in the orderbook
     *  if there is no next timestamp, wraps around to the start
     */
    std::string getNextTime(std::string timestamp);

private:
    std::vector<OrderBookEntry> orders;
};
#include "OrderBookEntry.h"

OrderBookEntry::OrderBookEntry(double _price,
                               double _amount,
                               string _timestamp,
                               string _product,
                               OrderBookType _orderType)
    : price(_price),
      amount(_amount),
      timestamp(_timestamp),
      product(_product),
      orderType(_orderType)
{
}

OrderBookType OrderBookEntry::stringToOrderBookType(const std::string &s)
{
  if(s == "ask")
  {
    return OrderBookType::ask;
  }
  else if( s == "bid")
  {
    return OrderBookType::bid;
  }
  else
  {
    return OrderBookType::unknown;
  }
}
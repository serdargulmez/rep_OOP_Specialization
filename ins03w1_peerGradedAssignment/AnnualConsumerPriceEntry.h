#pragma once

#include <string>

class AnnualConsumerPriceEntry
{
public:
    AnnualConsumerPriceEntry(std::string _countryName,
                             std::string _countryCode,
                             unsigned int _year,
                             double _price);

    std::string countryName;
    std::string countryCode;
    unsigned int year;
    double price;
    
    
};
#include "AnnualConsumerPriceEntry.h"
#include <string>

AnnualConsumerPriceEntry::AnnualConsumerPriceEntry(std::string _countryName,
                                                   std::string _countryCode,
                                                   unsigned int _year,
                                                   double _price)
    : countryName(_countryName),
      countryCode(_countryCode),
      year(_year),
      price(_price)
{
}
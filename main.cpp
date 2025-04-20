/*
--------------------------------------------------------------------------
--------------------------------------------------------------------------
--------------------------------------------------------------------------
--------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "OrderBookEntry.h"
using namespace std;

void printMenu()
{
    cout << "1: Print Help" << endl;
    cout << "2: Exchange Stats" << endl;
    cout << "3: Make an Offer" << endl;
    cout << "4: Make a Bid" << endl;
    cout << "5: Print Wallet" << endl;
    cout << "6: Continue" << endl;
    cout << "====================================" << endl;
}

void printHelp()
{
    cout << "Your aim is to make money." << endl;
}

void printMarketStats()
{
    cout << "Market looks good." << endl;
}

void enterOffer()
{
    cout << "Make an offer and enter the amount." << endl;
}

void enterBid()
{
    cout << "Make a bid and enter the amount." << endl;
}

void printWallet()
{
    cout << "Your wallet is empty." << endl;
}

void gotoNextTimeFrame()
{
    cout << "Going to next time frame." << endl;
}

int getUserOption()
{
    int userOption;
    cout << "Type in 1-6" << endl;
    cin >> userOption;
    cout << "You chose: " << userOption << endl;
    return userOption;
}

void processUserOption(int userOption)
{
    if (userOption == 1)
    {
        printHelp();
    }
    else if (userOption == 2)
    {
        printMarketStats();
    }
    else if (userOption == 3)
    {
        enterOffer();
    }
    else if (userOption == 4)
    {
        enterBid();
    }
    else if (userOption == 5)
    {
        printWallet();
    }
    else if (userOption == 6)
    {
        gotoNextTimeFrame();
    }
}

double computeAveragePrice(vector<OrderBookEntry> entries)
{
    double sum = 0.0;
    for (OrderBookEntry &e : entries)
    {
        sum += e.price;
    }

    double average = sum / entries.size();
    return average;
}

double computeLowPrice(vector<OrderBookEntry> entries)
{
    vector<double> prices;
    double minValue;
    for (OrderBookEntry &e : entries)
    {
        prices.push_back(e.price);
    }

    minValue = *min_element(prices.begin(), prices.end());
    return minValue;
}

double computeHighPrice(vector<OrderBookEntry> entries)
{
    vector<double> prices;
    double maxValue;
    for (OrderBookEntry &e : entries)
    {
        prices.push_back(e.price);
    }

    maxValue = *max_element(prices.begin(), prices.end());
    return maxValue;
}

double computePriceSpread(double maxValue, double minValue)
{
    return maxValue - minValue;
}

int main()
{
    cout << "--- Program Started ! ---" << endl;

    vector<OrderBookEntry> entries;
    entries.push_back(OrderBookEntry{8,
                                     7.44564869,
                                     "2020/03/17 17:01:24.884492",
                                     "ETH/BTC",
                                     OrderBookType::bid});
    entries.push_back(OrderBookEntry{2,
                                     7.44564869,
                                     "2020/03/17 17:01:24.884492",
                                     "ETH/BTC",
                                     OrderBookType::bid});
    entries.push_back(OrderBookEntry{6,
                                     7.44564869,
                                     "2020/03/17 17:01:24.884492",
                                     "ETH/BTC",
                                     OrderBookType::ask});

    for (OrderBookEntry& e : entries)
    {
        cout << "e: " << e.price << endl;
    }                                     

    double minValue = computeLowPrice(entries);
    double maxValue = computeHighPrice(entries);
    double average = computeAveragePrice(entries);
    double priceSpread = computePriceSpread(maxValue, minValue);

    cout << "The average of prices is: " << average << endl;
    cout << "The min value of prices is: " << minValue << endl;
    cout << "The max value of prices is: " << maxValue << endl;
    cout << "The price spread value of prices is: " << priceSpread << endl;

    // while (true)
    // {
    //     printMenu();
    //     int userOption = getUserOption();
    //     processUserOption(userOption);
    // }

    return 0;
}
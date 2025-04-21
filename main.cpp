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
using namespace std;

//  2020/03/17 17:01:24.884492,BTC/USDT,bid,5319.450228,0.00020075
enum class OrderBookType
{
    bid,
    ask
};

class OrderBookEntry
{
public:
    OrderBookEntry(double _price,
                   double _amount,
                   string _timestamp,
                   string _product,
                   OrderBookType _orderType);

    double price;
    double amount;
    string timestamp;
    string product;
    OrderBookType orderType;
};

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
    double minValue = entries[0].price;
    for (OrderBookEntry &e : entries)
    {
        if(e.price < minValue)
        {
            minValue = e.price;
        }
        
    }

    return minValue;
}

double computeHighPrice(vector<OrderBookEntry> entries)
{
    double maxValue = entries[0].price;
    for (OrderBookEntry &e : entries)
    {
        if(e.price > maxValue)
        {
            maxValue = e.price;
        }
        
    }

    return maxValue;
}

double computePriceSpread(vector<OrderBookEntry> entries)
{
    return computeHighPrice(entries) - computeLowPrice(entries); 
}

int main()
{
    cout << "--- Program Started ! ---" << endl;

    //  2020/03/17 17:01:24.884492,BTC/USDT,bid,5319.450228,0.00020075

    OrderBookEntry obe1{8,
                        7.44564869,
                        "2020/03/17 17:01:24.884492",
                        "ETH/BTC",
                        OrderBookType::bid};

    OrderBookEntry obe2{2,
                        7.44564869,
                        "2020/03/17 17:01:24.884492",
                        "ETH/BTC",
                        OrderBookType::bid};

    OrderBookEntry obe3{6,
                        7.44564869,
                        "2020/03/17 17:01:24.884492",
                        "ETH/BTC",
                        OrderBookType::ask};

    OrderBookEntry obe4{4,
                        7.44564869,
                        "2020/03/17 17:01:24.884492",
                        "ETH/BTC",
                        OrderBookType::ask};

    vector<OrderBookEntry> entries;
    entries.push_back(obe1);
    entries.push_back(obe2);
    entries.push_back(obe3);
    entries.push_back(obe4);

    // cout << "The obe1 of prices is: " << entries[0].price << endl;

    double minValue = computeLowPrice(entries);
    double maxValue = computeHighPrice(entries);
    double average = computeAveragePrice(entries);
    double priceSpread = computePriceSpread(entries);

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
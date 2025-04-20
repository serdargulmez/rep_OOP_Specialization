/*
--------------------------------------------------------------------------
--------------------------------------------------------------------------
--------------------------------------------------------------------------
--------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class OrderBookType
{
    bid,
    ask
};

class OrderBookEntry
{
public:
    /** Create a new OrderBookEntry with the price
     * set to the sent value
     */
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
    
}

double computeLowPrice(vector<OrderBookEntry> entries)
{
    
}

double computeHighPrice(vector<OrderBookEntry> entries)
{

}



int main()
{
    cout << "--- Program Started ! ---" << endl;

    OrderBookEntry obe1{0.02187308,
                        7.44564869,
                        "2020/03/17 17:01:24.884492",
                        "ETH/BTC",
                        OrderBookType::bid};

    OrderBookEntry obe2{0.12187308,
                        7.44564869,
                        "2020/03/17 17:01:24.884492",
                        "ETH/BTC",
                        OrderBookType::bid};

    vector<OrderBookEntry> entries;
    entries.push_back(obe1);
    entries.push_back(obe2);

    cout << "obe1.price: " << entries[0].price << endl;
    cout << "obe2.price: " << entries[1].price << endl;

    for( OrderBookEntry& e : entries)
    {
        cout << "entries: " << e.price << endl;
    }


    // while (true)
    // {
    //     printMenu();
    //     int userOption = getUserOption();
    //     processUserOption(userOption);
    // }

    return 0;
}
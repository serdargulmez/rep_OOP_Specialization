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

enum class OrderBookType{bid, ask};

class OrderBookEntry
{
    public:
        double price;
        double amount;
        string timestamp;
        string product;
        OrderBookType orderType;
};

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

int main()
{
    cout << "--- Program Started ! ---" << endl;
    
    // enum class OrderBookType{bid, ask};

    // double price = 5319.450228;
    // double amount = 0.00020075;
    // string timestamp{"2020/03/17 17:01:24.884492"};
    // string product{"BTC/USDT"};
    // OrderBookType orderType = OrderBookType::ask;

    // vector<double> prices;    
    // vector<double> amounts;
    // vector<string> timestamps;
    // vector<string> products;
    // vector<OrderBookType> orderTypes;

    // prices.push_back(234.56);
    // amounts.push_back(34.6);
    // timestamps.push_back("2020/03/17 17:01:24.884492");
    // products.push_back("BTC/USDT");
    // orderTypes.push_back(OrderBookType::bid);

    // prices.push_back(15.7);
    // amounts.push_back(2.6);
    // timestamps.push_back("2020/03/17 17:01:24.884492");
    // products.push_back("BTC/USDT");
    // orderTypes.push_back(OrderBookType::ask);




    // cout << "prices: " << prices[0] << endl;
    // cout << "prices: " << prices[1] << endl;



    // while (true)
    // {
    //     printMenu();
    //     int userOption = getUserOption();
    //     processUserOption(userOption);
    // }

    OrderBookEntry order1;

    order1.price = 10000;
    order1.amount = 0.002;
    order1.timestamp = "2020/03/17 17:01:24.884492";
    order1.product = "BTC/USDT";
    order1.orderType = OrderBookType::bid;

    cout << "The price is " << order1.price << "." << endl;

    return 0;
}
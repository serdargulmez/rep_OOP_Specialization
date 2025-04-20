#include "MerkelMain.h"
#include <iostream>
using namespace std;


MerkelMain::MerkelMain()
{

}

void MerkelMain::init()
{

}

void MerkelMain::printMenu()
{
    cout << "1: Print Help" << endl;
    cout << "2: Exchange Stats" << endl;
    cout << "3: Make an Offer" << endl;
    cout << "4: Make a Bid" << endl;
    cout << "5: Print Wallet" << endl;
    cout << "6: Continue" << endl;
    cout << "====================================" << endl;
}

void MerkelMain::printHelp()
{
    cout << "Your aim is to make money." << endl;
}

void MerkelMain::printMarketStats()
{
    cout << "Market looks good." << endl;
}

void MerkelMain::enterOffer()
{
    cout << "Make an offer and enter the amount." << endl;
}

void MerkelMain::enterBid()
{
    cout << "Make a bid and enter the amount." << endl;
}

void MerkelMain::printWallet()
{
    cout << "Your wallet is empty." << endl;
}

void MerkelMain::gotoNextTimeFrame()
{
    cout << "Going to next time frame." << endl;
}

int MerkelMain::getUserOption()
{
    int userOption;
    cout << "Type in 1-6" << endl;
    cin >> userOption;
    cout << "You chose: " << userOption << endl;
    return userOption;
}

void MerkelMain::processUserOption(int userOption)
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

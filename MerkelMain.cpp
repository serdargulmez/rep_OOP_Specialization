#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <map>


MerkelMain::MerkelMain()
{
}

void MerkelMain::init()
{
    int input;
    currentTime = orderbook.getEarliestTime();
    while (true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void MerkelMain::printMenu()
{
    std::cout << "1: Print Help" << std::endl;
    std::cout << "2: Exchange Stats" << std::endl;
    std::cout << "3: Make an Offer" << std::endl;
    std::cout << "4: Make a Bid" << std::endl;
    std::cout << "5: Print Wallet" << std::endl;
    std::cout << "6: Continue" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "Current time is: " << currentTime << std::endl;
    std::cout << "7: Print Changes" << std::endl;
}

void MerkelMain::printHelp()
{
    std::cout << "Your aim is to make money." << std::endl;
}

void MerkelMain::printMarketStats()
{
    
    for(std::string const p : orderbook.getKnownProducts())
    {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderbook.getOrders(OrderBookType::ask,
                                                                  p,
                                                                  currentTime);
        
        std::cout << "Asks: " << entries.size() << std::endl;
        std::cout << "Max Ask: " << orderbook.getHighPrice(entries) << std::endl;                                      
        std::cout << "Min Ask: " << orderbook.getLowPrice(entries) << std::endl;
    }

}

void MerkelMain::enterOffer()
{
    std::cout << "Make an offer and enter the amount." << std::endl;
}

void MerkelMain::enterBid()
{
    std::cout << "Make a bid and enter the amount." << std::endl;
}

void MerkelMain::printWallet()
{
    std::cout << "Your wallet is empty." << std::endl;
}

void MerkelMain::gotoNextTimeFrame()
{
    std::cout << "Going to next time frame." << std::endl;
    currentTime = orderbook.getNextTime(currentTime);
}

int MerkelMain::getUserOption()
{
    int userOption;
    std::cout << "Type in 1-6" << std::endl;
    cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
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
    else if (userOption == 7)
    {
        printChanges();
    }
}

void MerkelMain::printChanges()
{
    std::cout << "Changes are:" << std::endl;

    for(std::string const p : orderbook.getKnownProducts())
    {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderbook.getOrders(OrderBookType::ask,
                                                                  p,
                                                                  currentTime);
        
        std::cout << "Changes: %" << orderbook.getChange(entries) << std::endl;                                                    
                                                                        
    }   
}
#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <map>
#include<limits>



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
    std::cout << "3: Make an Ask" << std::endl;
    std::cout << "4: Make a Bid" << std::endl;
    std::cout << "5: Print Wallet" << std::endl;
    std::cout << "6: Continue" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "Current time is: " << currentTime << std::endl;
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

            
        entries = orderbook.getOrders(  OrderBookType::bid,
                                        p,
                                        currentTime);
        
        std::cout << "Bids: " << entries.size() << std::endl;
        std::cout << "Max Bid: " << orderbook.getHighPrice(entries) << std::endl;                                      
        std::cout << "Min Bid: " << orderbook.getLowPrice(entries) << std::endl;
    }

}

void MerkelMain::enterAsk()
{
    std::cout << "Make an ask and enter the amount: product,price,amount eg ETH/BTC,200,0.5" << std::endl;
    std::string input;
    std::getline(std::cin, input);
    std::vector<string> tokens = CSVReader::tokenise(input,',');

    if(tokens.size() != 3)
    {
        std::cout << "MerkelMain::enterAsk(): Bad input! : " << input << std::endl;
    }
    else
    {
        std::cout << "You typed: " << input << std::endl;
        try{
            OrderBookEntry obe = CSVReader::stringToOBE(tokens[1],
                                                        tokens[2],
                                                        currentTime,
                                                        tokens[0],
                                                        OrderBookType::ask);
            orderbook.insertOrder(obe);
        }
        catch(const std::exception &e)
        {
            std::cout << "MerkelMain::enterAsk(): Bad input! : " << input << std::endl;
        }
        
    }
}

void MerkelMain::enterBid()
{
    std::cout << "Make a bid and enter the amount: product,price,amount eg ETH/BTC,200,0.5" << std::endl;
    std::string input;
    std::getline(std::cin, input);
    std::vector<string> tokens = CSVReader::tokenise(input,',');

    if(tokens.size() != 3)
    {
        std::cout << "MerkelMain::enterBid(): Bad input! : " << input << std::endl;
    }
    else
    {
        std::cout << "You typed: " << input << std::endl;
        try{
            OrderBookEntry obe = CSVReader::stringToOBE(tokens[1],
                                                        tokens[2],
                                                        currentTime,
                                                        tokens[0],
                                                        OrderBookType::bid);
            orderbook.insertOrder(obe);
        }
        catch(const std::exception &e)
        {
            std::cout << "MerkelMain::enterBid(): Bad input! : " << input << std::endl;
        }
        
    }
}

void MerkelMain::printWallet()
{
    std::cout << "Your wallet is empty." << std::endl;
}

void MerkelMain::gotoNextTimeFrame()
{
    std::cout << "Going to next time frame." << std::endl;
    std::vector<OrderBookEntry> sales = orderbook.matchAsksToBids("ETH/BTC", currentTime);
    std::cout << "sales: " << sales.size() << std::endl;
    for(OrderBookEntry& sale : sales)
    {
        std::cout << "sale.price: " << sale.price << ", sale.amount: " << sale.amount << std::endl;
    }
    currentTime = orderbook.getNextTime(currentTime);
}

int MerkelMain::getUserOption()
{
    int userOption = 0;
    std::string line;
    std::cout << "Type in 1-6" << std::endl;
    std::getline(std::cin, line);
    try{
        userOption = std::stoi(line);

    }catch(const std::exception &e)
    {

    }
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
        enterAsk();
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


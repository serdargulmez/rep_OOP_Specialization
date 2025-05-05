#pragma once

#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"
class MerkelMain
{

public:
    MerkelMain();
    //** Call this function to start simulation */
    void init();

private:
    void printMenu();
    void printHelp();
    void printMarketStats();
    void enterOffer();
    void enterBid();
    void printWallet();
    void gotoNextTimeFrame();
    int getUserOption();
    void processUserOption(int userOption);

    OrderBook orderbook{"Tokenising.csv"};
    
};
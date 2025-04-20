#pragma once

#include <vector>
#include "OrderBookEntry.h"
class MerkelMain
{

public:
    MerkelMain();
    //** Call this to start sim */
    void init();

private:
    void loadOrderBook();
    void printMenu();
    void printHelp();
    void printMarketStats();
    void enterOffer();
    void enterBid();
    void printWallet();
    void gotoNextTimeFrame();
    int getUserOption();
    void processUserOption(int userOption);

    vector<OrderBookEntry> orders;
};
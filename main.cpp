/*
--------------------------------------------------------------------------
--------------------------------------------------------------------------
--------------------------------------------------------------------------
--------------------------------------------------------------------------
*/

#include <iostream>
#include "OrderBookEntry.h"
#include "MerkelMain.h"
#include "CSVReader.h"
#include "Wallet.h"

using namespace std;

int main()
{
    cout << "--- Program Started ! ---" << endl;

    // MerkelMain app{};
    // app.init();

    Wallet wallet;
    wallet.insertCurrency("BTC", 10);
    wallet.insertCurrency("USDT", 50);
    std::cout << wallet.toString() << std::endl;
    wallet.removeCurrency("BTC", 9);
    std::cout << wallet.toString() << std::endl;

    return 0;
}



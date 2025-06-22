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
    std::cout << "wallet has BTC " << wallet.containsCurrency("USDT", 10) << std::endl;
    std::cout << wallet.toString() << std::endl;

    return 0;
}



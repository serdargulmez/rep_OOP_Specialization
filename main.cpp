/*
--------------------------------------------------------------------------
--------------------------------------------------------------------------
--------------------------------------------------------------------------
--------------------------------------------------------------------------
*/

#include <iostream>
#include "OrderBookEntry.h"
#include "MerkelMain.h"
#include "identification.h"

using namespace std;

int main()
{
    cout << "--- Program Started ! ---" << endl;

    MerkelMain app{};
    app.init();
    
    // identification someone{};
    // someone.init();
    
    return 0;
}
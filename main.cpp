/*
--------------------------------------------------------------------------
--------------------------------------------------------------------------
--------------------------------------------------------------------------
--------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "--- Program Started ! ---" << endl;

    while (true)
    {
        cout << "1: Print Help" << endl;
        cout << "2: Exchange Stats" << endl;
        cout << "3: Make an Offer" << endl;
        cout << "4: Make a Bid" << endl;
        cout << "5: Print Wallet" << endl;
        cout << "6: Continue" << endl;
        cout << "====================================" << endl;

        unsigned short userOption;

        cout << "Type in 1-6" << endl;
        cin >> userOption;

        if (userOption == 0)
        {
            cout << "Invalid option. Try to type 1-6 !!!" << endl;
        }
        else if (userOption == 1)
        {
            cout << "Your aim is to make money." << endl;
        }
        else if (userOption == 2)
        {
            cout << "Market looks good." << endl;
        }
        else if (userOption == 3)
        {
            cout << "Make an offer and enter the amount." << endl;
        }
        else if (userOption == 4)
        {
            cout << "Make a bid and enter the amount." << endl;
        }
        else if (userOption == 5)
        {
            cout << "Your wallet is empty." << endl;
        }
        else if (userOption == 6)
        {
            cout << "Going to next time frame." << endl;
        }
    }

    return 0;
}
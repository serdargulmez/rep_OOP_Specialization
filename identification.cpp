

#include "identification.h"
#include <iostream>
using namespace std;

identification::identification()
{
}

void identification::init()
{
    userInput = getAge();
    calculateWeight(userInput);
}

int identification::getAge()
{
    int entry;
    cout << "Enter your age, please!" << endl;
    cin >> entry;
    return entry;
}

void identification::calculateWeight(int entryForCalculateAge)
{
    switch (entryForCalculateAge)
    {
    case 0 ... 20:
        cout << "Weight is between 0-60." << endl;
        break;
    case 21:
        cout << "Weight is 70." << endl;
        break;
    default:
        cout << "Weight is bigger than 80." << endl;
        break;
    }
}

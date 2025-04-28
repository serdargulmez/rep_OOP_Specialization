/*
--------------------------------------------------------------------------
--------------------------------------------------------------------------
--------------------------------------------------------------------------
--------------------------------------------------------------------------


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

*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "OrderBookEntry.h"

std::vector<std::string> tokenise(std::string csvLine, char separator)
{
    std::vector<std::string> tokens;
    signed int start, end;
    std::string token;
    start = csvLine.find_first_not_of(separator, 0);
    do
    {
        end = csvLine.find_first_of(separator, start);
        if (start == csvLine.length() || start == end)
            break;
        if (end >= 0)
            token = csvLine.substr(start, end - start);
        else
            token = csvLine.substr(start, csvLine.length() - start);
        tokens.push_back(token);
        start = end + 1;
        //}while(end > 0);
        // slight change from the video -
        // find_first_of returns std::string::npos
        // not 'less than zero'
    } while (end != std::string::npos);
    return tokens;
}

int main()
{
    std::string csvFilename{"Tokenising_test.csv"};
    std::ifstream csvFile{csvFilename};
    std::string line;
    unsigned int lineCount = 0;

    if (csvFile.is_open())
    {
        std::cout << "Opened file: " << csvFilename << std::endl;
    }
    else
    {
        std::cout << "Problem opening file " << csvFilename << std::endl;
    }

    while (getline(csvFile, line))
    {
        lineCount++;
        std::vector<std::string> tokens = tokenise(line, ',');
        std::cout << "Read " << tokens.size() << " tokens " << std::endl;
        // 2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869
        if (tokens.size() != 5)
        {
            std::cout << "Tokens size is invalid!" << std::endl;
            break;
        }

        std::string timestamp = tokens[0];
        std::string product = tokens[1];

        OrderBookType orderType;
        if (tokens[2] == "bid")
            orderType = OrderBookType::bid;
        else
            orderType = OrderBookType::ask;
        try
        {
            double price = std::stod(tokens[3]);
            double amount = std::stod(tokens[4]);
        }
        catch (std::exception &e)
        {
            continue;
        }

        for (std::string &t : tokens)
        {
            std::cout << t << std::endl;
        }
    }

    std::cout << "Line counts are: " << lineCount << std::endl;

    // don't forget to close it!
    csvFile.close();
    return 0;
}

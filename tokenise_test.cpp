#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "OrderBookEntry.h"

std::vector<std::string> tokenise(std::string csvLine, char separator)
{
    // vector string tokens    ## stores the tokens
        std::vector<std::string> tokens;
    // int start, end  ## used to delineate the position of the tokens
        signed int start, end;
        std::string token;
    // start = csvLine.find_first_not_of(separator)
        start = csvLine.find_first_not_of(separator, 0);
    // do
        do
        {
    //     end = next 'separator' after start
            end = csvLine.find_first_of(separator, start);
    //     if start == csvLine.length or start == end  ## nothing more to find
    //         break
            if(start == csvLine.length() || start == end) break;
    //     if end >= 0 ## we found the separator
            if(end >= 0) token = csvLine.substr(start, end - start);
    //         token = csvLine.substr(start, end - start)  ## start substring length
    //     else
            else token = csvLine.substr(start, csvLine.length() - start);
    //         token = csvLine.substr(start, csvLine.length - start)  ## end is invalid
    //     tokens.push_back(token) ## save the token
            tokens.push_back(token);
    //     start = end + 1 ## move past this token
            start = end + 1;
    // while (end > 0)  ## continue loop condition
        } while(end != std::string::npos); // while (end != std::string::npos); this is the most correct code

    return tokens;
}

int main()
{
    // std::vector<std::string> tokens;

    // std::string csvLine = "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869";
    // tokens = tokenise(csvLine, ',');

    // for(std::string& t : tokens)
    // {
    //     std::cout << t << std::endl;
    // }

    /*
        You might have to adjust the contents of the csvFilename string, so it points to
        the place where you have put the CSV file. E.g. if you put it in a temp folder
        on your windows C drive:
        std::string csvFilename{"C:\temp\20200317.csv"};
    */
    std::ifstream csvFile{"Tokenising_test.csv"};
    std::string line;
    std::vector<std::string> tokens;

    if (csvFile.is_open())
    {
        std::cout << "File opened..." << std::endl;

        unsigned int lineCount = 0;

        while (std::getline(csvFile, line))
        {
            lineCount++;
            std::cout << "Read line: " << line << std::endl;
            tokens = tokenise(line, ',');

            if(tokens.size() != 5)  // wrong line type
            {
                std::cout << "This line has error!" << std::endl;
                continue;
            }
            // we have 5 tokens

            std::string timestamp = tokens[0];
            std::string product = tokens[1];
            OrderBookType orderType = OrderBookEntry::stringToOrderBookType(tokens[2]);
            try{
                
                double price = std::stod(tokens[3]);
                double amount = std::stod(tokens[4]);                
                std::cout << price << ":" << amount << std::endl;

            }catch(std::exception& e)
            {
                std::cout << "Bad float! :" << tokens[3] << std::endl;
                std::cout << "Bad float! :" << tokens[4] << std::endl;
                break;               
            }
            
          
        }

        std::cout << "total line count: " << lineCount << std::endl;
        csvFile.close();
    }
    else
    {
        std::cout << "File could not opened!" << std::endl;
    }

    return 0;
}
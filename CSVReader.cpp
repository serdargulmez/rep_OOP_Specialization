#include "CSVReader.h"
#include <iostream>
#include <fstream>

CSVReader::CSVReader()
{
}

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFileName)
{
    std::vector<OrderBookEntry> entries;
    std::ifstream csvFile{csvFileName};
    std::string line;
    
    if (csvFile.is_open())
    {
        std::cout << "File opened..." << std::endl;
        while (std::getline(csvFile, line))
        {
            try{
                OrderBookEntry obe = stringToOBE(tokenise(line, ',')); 
                entries.push_back(obe);
            }catch(const std::exception &e){
                std::cout << "CSVReader::readCSV Bad data." << std::endl; 
            }
        }
    }

    std::cout << "CSVReader::readCSVFile: " << entries.size() << " entries." << std::endl; 
    csvFile.close();
    return entries;
}

std::vector<string> CSVReader::tokenise(std::string csvLine, char separator)
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
    } while (end != std::string::npos); // while (end != std::string::npos); this is the most correct code

    return tokens;
}

OrderBookEntry CSVReader::stringToOBE(std::vector<std::string> tokens)
{
    double price, amount;

    if (tokens.size() != 5) // wrong line type
    {
        std::cout << "Bad line!" << std::endl;
        throw std::exception{};
    }
    // we have 5 tokens

    std::string timestamp = tokens[0];
    std::string product = tokens[1];
    OrderBookType orderType = OrderBookEntry::stringToOrderBookType(tokens[2]);
    try
    {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    }
    catch (const std::exception &e)
    {
        std::cout << "Bad float! :" << tokens[3] << std::endl;
        std::cout << "Bad float! :" << tokens[4] << std::endl;
        throw;
    }

    OrderBookEntry obe{price,
                       amount,
                       tokens[0],
                       tokens[1],
                       OrderBookEntry::stringToOrderBookType(tokens[2])};

    return obe;
}
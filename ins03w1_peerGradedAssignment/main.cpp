/*
Annual Consumer Price Index
Annual Consumer Price Index (CPI) for most countries in the world

About this file

Suggest Edits
Annual Consumer Price Index (CPI) for most countries
in the world when it has been measured. The reference year
is 2005 (meaning the value of CPI for all countries is 100
and all other CPI values are relative to that year).

Data
The data comes from The World Bank and is collected from 1960 to 2011.
There are some values missing from data so users of the data will
have to guess what should be in the empty slots.

The actual download happens via The World Bank's API (with csv as the requested format).

Columns are 'Country,Country Code,Year,CPI'
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "AnnualConsumerPriceEntry.h"

std::vector<std::string> tokenise(std::string row, char separator)
{
    std::vector<std::string> tokens;
    signed int start, end;
    std::string token;

    start = row.find_first_not_of(separator, 0);

    do
    {
        end = row.find_first_of(separator, start);
        if (start == row.length() || start == end)
        {
            break;
        }

        if (end >= 0)
        {
            token = row.substr(start, end - start);
        }
        else
        {
            token = row.substr(start, row.length());
        }

        tokens.push_back(token);

        start = end + 1;

    } while (end != std::string::npos);

    return tokens;
}

int main()
{
    std::string csvFileName = "AnnualConsumerPrice.csv";
    std::ifstream csvFile{csvFileName};
    std::string row;
    unsigned int totalRowCount = 0;
    unsigned int invalidRowCount = 0;
    unsigned int validRowCount = 0;
    std::vector<AnnualConsumerPriceEntry> entries;

    if (csvFile.is_open())
    {
        std::cout << "Opened file is: " << csvFileName << std::endl;
    }
    else
    {
        std::cout << "File couldn't opened!" << std::endl;
    }

    while (getline(csvFile, row))
    {
        totalRowCount++;
        // std::cout << "Row " << totalRowCount << ": " << row << std::endl;
        std::vector<std::string> tokens = tokenise(row, ',');

        std::string countryName = "";
        std::string countryCode = "";
        unsigned int year = 0;
        double price = 0;

        if (tokens.size() != 4)
        {
            invalidRowCount++;
            std::cout << "Row number: " << totalRowCount << " is invalid!" << std::endl;
            continue;
        }
        else
        {
            validRowCount++;
        }

        countryName = tokens[0];
        countryCode = tokens[1];

        try
        {
            year = std::stoi(tokens[2]);
            price = std::stod(tokens[3]);
        }
        catch (std::exception &e)
        {
            invalidRowCount++;
            validRowCount--;
            std::cout << "Row number: " << totalRowCount << " has invalid data type!" << std::endl;
            continue;
        }

        entries.push_back(AnnualConsumerPriceEntry{countryName,
                                                   countryCode,
                                                   year,
                                                   price});
    }

    std::cout << "Entries first index country name is: " << entries[0].countryName << "." << std::endl;
    std::cout << "Entries last index country name is: " << entries[entries.size() - 1].countryName << "." << std::endl;

    std::cout << "Total row count is: " << totalRowCount << "." << std::endl;
    std::cout << "Invalid row count is: " << invalidRowCount << "." << std::endl;
    std::cout << "Valid row count is: " << validRowCount << "." << std::endl;

    if (invalidRowCount > 0 && invalidRowCount == 1)
    {
        std::cout << "Check out invalid row!!!" << std::endl;
    }
    else if (invalidRowCount > 1)
    {
        std::cout << "Check out invalid rows!!!" << std::endl;
    }
    else
    {
        std::cout << "All data inputs are compatible with program..." << std::endl;
    }

    csvFile.close();
    return 0;
}
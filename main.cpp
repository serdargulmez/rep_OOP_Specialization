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
// #include <vector>


int main()
{
    std::string csvFileName = "AnnualConsumerPrice.csv";
    std::ifstream csvFile{csvFileName};
    std::string row;

    if(csvFile.is_open())
    {
        std::cout << "Opened file is: " << csvFileName << std::endl;
    }
    else
    {
        std::cout << "File couldn't opened!" << std::endl;
    }

    // row checked
    // getline(csvFile,row);
    // std::cout << "row: " << row << std::endl;

    

    csvFile.close();
    return 0;
}
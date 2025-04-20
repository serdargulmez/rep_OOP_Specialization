#include <iostream>
#include <string>
#include <vector>

// Define the OrderBookType enum class
enum class OrderBookType {bid, ask, unknown};

// Define the OrderBookEntry class to model a row in the trading dataset
class OrderBookEntry
{
public:
    // Constructor that takes all fields as parameters
    OrderBookEntry(double _price, 
                  double _amount, 
                  std::string _timestamp, 
                  std::string _product, 
                  OrderBookType _orderType)
        : price(_price), 
          amount(_amount), 
          timestamp(_timestamp),
          product(_product), 
          orderType(_orderType)
    {
        // Using member initializer list, no additional code needed here
    }
    
    // Function to convert string to OrderBookType
    static OrderBookType stringToOrderBookType(std::string s)
    {
        if (s == "ask")
        {
            return OrderBookType::ask;
        }
        if (s == "bid")
        {
            return OrderBookType::bid;
        }
        return OrderBookType::unknown;
    }

    // Data members to represent each field in the dataset
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
};

// Function to compute the average price from a vector of OrderBookEntry objects
double computeAveragePrice(std::vector<OrderBookEntry>& entries)
{
    double total = 0.0;
    for (OrderBookEntry& e : entries)
    {
        total += e.price;
    }
    return total / entries.size();
}

// Function to compute the lowest price from a vector of OrderBookEntry objects
double computeLowPrice(std::vector<OrderBookEntry>& entries)
{
    double lowest = entries[0].price;
    for (OrderBookEntry& e : entries)
    {
        if (e.price < lowest)
        {
            lowest = e.price;
        }
    }
    return lowest;
}

// Function to compute the highest price from a vector of OrderBookEntry objects
double computeHighPrice(std::vector<OrderBookEntry>& entries)
{
    double highest = entries[0].price;
    for (OrderBookEntry& e : entries)
    {
        if (e.price > highest)
        {
            highest = e.price;
        }
    }
    return highest;
}

// Function to compute the price spread (highest - lowest) from a vector of OrderBookEntry objects
double computePriceSpread(std::vector<OrderBookEntry>& entries)
{
    double a = computeHighPrice(entries) - computeLowPrice(entries);
    return a;
}

// Application menu functions
void printMenu()
{
    // 1 print help
    std::cout << "1: Print help " << std::endl;
    // 2 print exchange stats
    std::cout << "2: Print exchange stats" << std::endl;
    // 3 make an offer
    std::cout << "3: Make an offer " << std::endl;
    // 4 make a bid 
    std::cout << "4: Make a bid " << std::endl;
    // 5 print wallet
    std::cout << "5: Print wallet " << std::endl;
    // 6 continue   
    std::cout << "6: Continue " << std::endl;

    std::cout << "============== " << std::endl;
}

void printHelp()
{
    std::cout << "Help - your aim is to make money. Analyze the market and make bids and offers." << std::endl;
}

void printMarketStats(std::vector<OrderBookEntry>& orders)
{
    std::cout << "Market stats for the order book:" << std::endl;
    std::cout << "Average price: " << computeAveragePrice(orders) << std::endl;
    std::cout << "Low price: " << computeLowPrice(orders) << std::endl;
    std::cout << "High price: " << computeHighPrice(orders) << std::endl;
    std::cout << "Price spread: " << computePriceSpread(orders) << std::endl;
}

void enterOffer(std::vector<OrderBookEntry>& orders)
{
    std::cout << "Make an offer - enter the amount: product,price, amount, eg  ETH/BTC,200,0.5" << std::endl;
}

void enterBid(std::vector<OrderBookEntry>& orders)
{
    std::cout << "Make a bid - enter the amount: product,price, amount, eg  ETH/BTC,200,0.5" << std::endl;
}

void printWallet()
{
    std::cout << "Your wallet is empty. " << std::endl;
}
        
void gotoNextTimeframe()
{
    std::cout << "Going to next time frame. " << std::endl;
}
 
int getUserOption()
{
    int userOption;
    std::string line;
    std::cout << "Type in 1-6" << std::endl;
    std::getline(std::cin, line);
    try{
        userOption = std::stoi(line);
    }catch(const std::exception& e)
    {
        userOption = 0;
    }
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

void processUserOption(int userOption, std::vector<OrderBookEntry>& orders)
{
    if (userOption == 0)
    {
        std::cout << "Invalid choice. Choose 1-6" << std::endl;
    }
    if (userOption == 1)
    {
        printHelp();
    }
    if (userOption == 2)
    {
        printMarketStats(orders);
    }
    if (userOption == 3)
    {
        enterOffer(orders);
    }
    if (userOption == 4)
    {
        enterBid(orders);
    }
    if (userOption == 5)
    {
        printWallet();
    }
    if (userOption == 6)
    {
        gotoNextTimeframe();
    }
}

int main()
{
    // Create a vector of OrderBookEntry objects
    std::vector<OrderBookEntry> orders;
    
    // Add some sample order book entries to the vector
    orders.push_back(OrderBookEntry{0.02187308, 7.44564869, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid});
    orders.push_back(OrderBookEntry{0.02186299, 0.1, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid});
    orders.push_back(OrderBookEntry{0.02187000, 5.0, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::ask});
    orders.push_back(OrderBookEntry{0.02189000, 2.5, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::ask});
    orders.push_back(OrderBookEntry{0.02185000, 1.0, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid});
    
    // Print all orders in the vector using a range-based loop
    std::cout << "All orders in the vector:" << std::endl;
    for (OrderBookEntry& order : orders)
    {
        std::cout << "Type: " << (order.orderType == OrderBookType::bid ? "Bid" : "Ask")
                  << ", Price: " << order.price
                  << ", Amount: " << order.amount
                  << ", Product: " << order.product
                  << ", Time: " << order.timestamp << std::endl;
    }
    
    // Calculate and print statistics on the order book
    std::cout << "\nOrder Book Statistics:" << std::endl;
    std::cout << "Average Price: " << computeAveragePrice(orders) << std::endl;
    std::cout << "Lowest Price: " << computeLowPrice(orders) << std::endl;
    std::cout << "Highest Price: " << computeHighPrice(orders) << std::endl;
    std::cout << "Price Spread: " << computePriceSpread(orders) << std::endl;
    
    // Demonstrate alternative way to iterate over the vector using indices
    std::cout << "\nIterating with indices:" << std::endl;
    for (unsigned int i = 0; i < orders.size(); ++i)
    {
        std::cout << "Order " << i << " price: " << orders[i].price << std::endl;
    }
    
    // Start the interactive menu
    std::cout << "\nStarting the trading platform menu..." << std::endl;
    int userOption;
    while(true)
    {
        printMenu();
        userOption = getUserOption();
        processUserOption(userOption, orders);
    }
    
    return 0;
}
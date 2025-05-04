#include <string> 

int main()
{
  std::string csvLine = "first, second, third";
  char separator = ",";
  int start = csvLine.find_first_not_of(separator);
}

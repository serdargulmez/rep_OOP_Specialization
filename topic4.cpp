#include <string>
#include <iostream>
#include <fstream>
int main(){
   std::ifstream csvFile{"file.csv"};
   if(csvFile.is_open()){
      std::cout << "File open" << std::endl;
   }
   else{
      std::cout << "Could not open file" << std::endl;
   }
}

#include <iostream>

int sum(int num1, int num2){
   return num1 + num2;
}

int main(){
   try{
      int result = sum(5, 5);
      if (result < 20){
         throw result;
      }
      std::cout << "Here is the result" << std::endl;
   }
   catch (int& result){
      std::cout << "The sum should be at least 20" << std::endl;
   }
   return 0;
};


// int main()
// {
//     double d = 0;
//     std::string s = "asdasd";

//     try{

//         d = std::stod(s);
    
//     }catch(const std::exception& e)
//     {
        
//     }
    
//     std::cout << "d: " << d << std::endl;
    
//     return 0;
// }
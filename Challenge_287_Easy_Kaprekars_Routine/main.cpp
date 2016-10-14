#include <iostream>
#include <string>

char largest_digit(std::string num){
  char largest = '0';
  for(int i = 0; i < num.length(); i++){
    if(num.at(i) > largest){
      largest = num.at(i);
    }
  }
  return largest;
}

std::string desc_order(std::string num){
 std::string ordered = "";
 while(num.length() > 0){
   char tmp = '0';
   int largestPos = 0;

   for(int i = 0; i < num.length(); i++){
     if(num.at(i) > tmp){
       tmp = num.at(i);
       largestPos = i;
     }
   }

   ordered += tmp;
   num.erase(largestPos,1);
 }
   return ordered;
}

std::string asc_order(std::string num){
 std::string ordered = "";
 while(num.length() > 0){
   char tmp = '9';
   int smallestPos = 0;

   for(int i = 0; i < num.length(); i++){
     if(num.at(i) < tmp){
       tmp = num.at(i);
       smallestPos = i;
     }
   }

   ordered += tmp;
   num.erase(smallestPos,1);
 }
   return ordered;
}

int kaprekarIterations(int num){
  int count = 0;

  //6174 is Kaprekar's constant, will never change after.
  while(num != 6174){
    while(num < 1000){
      num *= 10;
    }
    int desc = std::stoi(desc_order(std::to_string(num)));
    int asc = std::stoi(asc_order(std::to_string(num)));
    //std::cout << "desc: " << desc << " asc: " << asc << std::endl;
    num = desc-asc;
    count++;
  }
  return count;
}

int largestKaprekarIterations(int num){
  int mostIterations = 0;

  //6174 is Kaprekar's constant, will never change after.
  while((num / 10000) < 1){
    num++;

    //are there at least 2 different digits
    if(std::to_string(num).at(0)==std::to_string(num).at(1) &&
    std::to_string(num).at(2)==std::to_string(num).at(3) &&
    std::to_string(num).at(0)==std::to_string(num).at(3)){
      num++;
      if(num > 9999){
        break;
      }
    }

    int iterations = kaprekarIterations(num);
    if(iterations > mostIterations){
      mostIterations = iterations;
    }
  }

  return mostIterations;
}

int main(){
  std::cout << "Largest digits\n";
  std::cout << "1234 -> " << largest_digit("1234") << std::endl;
  std::cout << "3253 -> " << largest_digit("3253") << std::endl;
  std::cout << "9800 -> " << largest_digit("9800") << std::endl;
  std::cout << "3333 -> " << largest_digit("3333") << std::endl;
  std::cout << "120 -> " << largest_digit("120") << std::endl;
  std::cout << "916480 -> " << largest_digit("916480") << std::endl
  << std::endl;

  std::cout << "Decending order\n";
  std::cout << "1234 -> " << desc_order("1234") << std::endl;
  std::cout << "3253 -> " << desc_order("3253") << std::endl;
  std::cout << "9800 -> " << desc_order("9800") << std::endl;
  std::cout << "3333 -> " << desc_order("3333") << std::endl;
  std::cout << "120 -> " << desc_order("120") << std::endl;
  std::cout << "916480 -> " << desc_order("916480") << std::endl
  << std::endl;

  std::cout << "Kaprekar's Routine Iterations\n";
  std::cout << "1234 -> " << kaprekarIterations(1234) << std::endl;
  std::cout << "3253 -> " << kaprekarIterations(3253) << std::endl;
  std::cout << "9800 -> " << kaprekarIterations(9800) << std::endl;
  std::cout << "6589 -> " << kaprekarIterations(6589) << std::endl;
  std::cout << "5455 -> " << kaprekarIterations(5455) << std::endl;
  std::cout << "6174 -> " << kaprekarIterations(6174) << std::endl
  << std::endl;

  std::cout << "Most iterations: " << largestKaprekarIterations(1000)
  << std::endl;
}

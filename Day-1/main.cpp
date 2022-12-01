#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int dayOne() {
  std::ifstream input("input.txt");
  std::string line;
  int max = 0;
  int count = -1;
  while (std::getline(input, line)) {
    if (line == "") count = 0;
    else count += std::stoi(line);
    if (count > max) max = count;
  }
  return max;
}

int dayTwo() {
  std::ifstream input("input.txt");
  std::string line;
  int max[3] = {};
  int count = 0;
  int tmp = -1;
  
  while (std::getline(input, line)) {
    if (line == "") count = 0;
    else count += std::stoi(line);

    if (count > max[0]) {
      max[0] = count;
      for(int i = 1; i < 3; i++) {
        if (max[i-1] < max[i]) break;
        tmp = max[i];
        max[i] = max[i-1];
        max[i-1] = tmp;
      }
    }
    
  }
  return max[0] + max[1] + max[2];
}


int main() { 
  std::cout << "Day 1: " << dayOne() << "\n"; 
  std::cout << "Day 2: " << dayTwo() << "\n"; 
}

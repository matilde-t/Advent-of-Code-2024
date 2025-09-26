#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ifstream input("input");
  std::string line;
  std::string delimiter = " ";
  int number1;
  int number2;
  int pos1;
  int pos2;
  int sum = 0;
  bool ascend;
  bool descend;
  bool first_num;
  bool check;

  while (std::getline(input, line)) {
    pos1 = 0;
    ascend = true;
    descend = true;
    first_num = true;
    do {
      pos2 = line.find(delimiter, pos1);
      if (pos2 == -1) {
        pos2 = line.size();
      }
      number2 = std::stoi(line.substr(pos1, pos2));
      pos1 = pos2 + 1;
      if (first_num) {
        number1 = number2;
        first_num = false;
        check = true;
        continue;
      } else {
        if (0 < std::abs(number1 - number2) &&
            std::abs(number1 - number2) <= 3) {
          if (number2 > number1) {
            descend = false;
          } else {
            ascend = false;
          }
        } else {
          ascend = true;
          descend = true;
          break;
        }
        check = ascend != descend;
      }
      number1 = number2;
    } while (pos2 != line.size() && check);

    if (ascend != descend) {
      sum++;
    }
  }

  std::cout << sum << std::endl;
  return 0;
}
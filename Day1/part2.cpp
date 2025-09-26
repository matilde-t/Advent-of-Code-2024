#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
  std::ifstream input("input");
  std::string line;
  std::string delimiter = "   ";
  std::string left_list;
  std::string right_list;
  int left_number;
  int right_number;
  std::vector<int> left_vec;
  std::unordered_map<int, size_t> right_map;
  int pos;

  while (std::getline(input, line)) {
    pos = line.find((delimiter));
    left_number = std::stoi(line.substr(0, pos));
    right_number = std::stoi(line.substr(pos + delimiter.length()));
    left_vec.push_back(left_number);
    right_map[right_number]++;
  }

  int sum = 0;
  for (int i : left_vec) {
    sum += i * right_map[i];
  }
  std::cout << sum << std::endl;
  return 0;
}
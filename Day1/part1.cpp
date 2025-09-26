#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
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
  std::vector<int> right_vec;
  int pos;

  while (std::getline(input, line)) {
    pos = line.find((delimiter));
    left_number = std::stoi(line.substr(0, pos));
    right_number = std::stoi(line.substr(pos + delimiter.length()));
    left_vec.push_back(left_number);
    right_vec.push_back(right_number);
  }

  std::sort(left_vec.begin(), left_vec.end());
  std::sort(right_vec.begin(), right_vec.end());

  int sum = 0;
  for (int i = 0; i < left_vec.size(); i++) {
    sum += std::abs(left_vec[i] - right_vec[i]);
  }
  std::cout << sum << std::endl;
  return 0;
}
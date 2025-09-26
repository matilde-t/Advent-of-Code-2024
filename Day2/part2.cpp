#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool correct_dist(int number1, int number2) {
  return 0 < std::abs(number1 - number2) && std::abs(number1 - number2) <= 3;
}

bool ascending(int number1, int number2) { return number2 > number1; }

std::vector<int> read_line(std::string line) {
  std::string delimiter = " ";
  int pos1 = 0;
  int pos2;
  std::vector<int> line_vec;
  int number;
  do {
    pos2 = line.find(delimiter, pos1);
    if (pos2 == -1) {
      pos2 = line.size();
    }
    number = std::stoi(line.substr(pos1, pos2));
    line_vec.push_back(number);
    pos1 = pos2 + 1;

  } while (pos2 != line.size());
  return line_vec;
}

bool check_vec(std::vector<int> line_vec) {
  int number1;
  int number2;
  std::vector<bool> is_ascending;
  for (size_t i = 0; i < line_vec.size() - 1; i++) {
    number1 = line_vec[i];
    number2 = line_vec[i + 1];
    if (correct_dist(number1, number2)) {
      is_ascending.push_back(ascending(number1, number2));
    } else {
      return false;
    }
  }
  bool all_true = std::all_of(is_ascending.begin(), is_ascending.end(),
                              [](bool v) { return v; });

  bool all_false = std::all_of(is_ascending.begin(), is_ascending.end(),
                               [](bool v) { return !v; });

  return all_true || all_false;
}

void print_vec(std::vector<int> vec) {
  for (int el : vec) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
  return;
}

int main() {
  std::ifstream input("input");
  std::string line;
  std::vector<int> line_vec;
  bool check = false;
  int sum = 0;

  while (std::getline(input, line)) {
    check = false;
    line_vec = read_line(line);
    print_vec(line_vec);
    if (check_vec(line_vec)) {
      check = true;
    } else {
      for (int i = 0; i < line_vec.size(); i++) {
        std::vector new_vec = line_vec;
        new_vec.erase(new_vec.begin() + i);
        if (check_vec(new_vec)) {
          check = true;
          break;
        }
      }
    }
    if (check) {
      sum++;
      std::cout << "SAFE" << std::endl;
    } else {
      std::cout << "UNSAFE" << std::endl;
    }
  }
  std::cout << sum << std::endl;
  return 0;
}
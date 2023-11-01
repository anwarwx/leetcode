#include <iostream>
#include <vector>

void print(std::vector<int>& v);

int maxProfit(std::vector<int>& prices) {}

void print(std::vector<int>& v) {
  unsigned int i = 0; std::cout << '[';
  for (; i < v.size()-1; i++) {
    std::cout << v.at(i) << ", ";
  }
  std::cout << v.at(i) << "]\n";
}

int main() {
  std::vector<int> v1 {7,1,5,3,6,4};
  int ret = maxProfit(v1); // 5
  std::cout << ret << '\n';

  std::vector<int> v2 {7,6,4,3,1};
  ret = maxProfit(v2); // 0
  std::cout << ret << '\n';

  return 0;
}

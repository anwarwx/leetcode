#include <iostream>
#include <vector>
#include <map>

int majorityElement(std::vector<int>& nums) {
  const int o = nums.size()/2;
  std::map<int, int> m;

  for (int n : nums) {
    if (m.count(n)) m[n]++;
    else m[n] = 1;
  }

  for (auto [k, v] : m) if (v > o) return k;

  return 1;
}

void print(std::vector<int>& nums) {
  unsigned int i = 0; std::cout << '[';
  for (; i < nums.size()-1; i++) {
    std::cout << nums.at(i) << ", ";
  }
  std::cout << nums.at(i) << "]\n";
}

int main() {
  std::vector<int> nums {2,2,1,1,1,2,2};
  std::cout << majorityElement(nums) << '\n';

  return 0;
}

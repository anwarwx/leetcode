#include <iostream>
#include <vector>

void print(std::vector<int>& nums);

void rotate(std::vector<int>& nums, int k) {}

void print(std::vector<int>& nums) {
  unsigned int i = 0; std::cout << '[';
  for (; i < nums.size()-1; i++) {
    std::cout << nums.at(i) << ", ";
  }
  std::cout << nums.at(i) << "]\n";
}

int main() {
  std::vector<int> nums1 {1,2,3,4,5,6,7};
  rotate(nums1, 3); // [5, 6, 7, 1, 2, 3, 4]
  print(nums1);


  std::vector<int> nums2 {-1,-100,3,99};
  rotate(nums2, 2); // [3,99,-1,-100]
  print(nums2);

  return 0;
}

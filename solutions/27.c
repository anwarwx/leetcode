#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val) {
    const int l = numsSize;
    unsigned int i = 0;
    int k = 0, h = 0;
    
    for (; i < l; i++) {
        if (nums[i] == val) k+=1;
        if (h < nums[i]) h=nums[i];
    }

    for (i = 0; i < l; i++) if (nums[i] == val) nums[i] = h+1;

    unsigned int j;
    for (i = 0; i < l; i++) {
        for (j = i+1; j < l; j++) {
            if (nums[i] > nums[j]) {
                int t = nums[j];
                nums[j] = nums[i];
                nums[i] = t;
            }
        }
    }

    i = l - k;
    for (; i < l; i++) nums[i] = -1;
    
    return l-k;
}

void print(int* arr, int size) {
  printf("[");
  unsigned int i = 0;
  for (; i < size-1; i++) {
    printf("%d, ", arr[i]);
  }
  printf("%d]\n", arr[i]);
}

int main(void) {
  int *nums = malloc(sizeof(int)*4);
  int b1[4] = {3,2,2,3};

  unsigned int i = 0;
  for (; i < 4; i++) nums[i] = b1[i];
  
  removeElement(nums, 4, 3); // [2,2]

  print(nums, 4);
  free(nums);

  // ***

  nums = malloc(sizeof(int)*8);
  int b2[8] = {0,1,2,2,3,0,4,2};

  for (i = 0; i < 8; i++) nums[i] = b2[i];

  removeElement(nums, 8, 2); // [0,1,4,0,3]

  print(nums, 8);
  free(nums);

  return 0;
}

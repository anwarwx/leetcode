#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    const int l = numsSize;
    unsigned int i = 0, m = 0;
    int h[l];
    
    for(; i < l; i++) {
        if (m < nums[i]) m = nums[i];
        h[i] = -1;
    }
    
    unsigned int j, k = 0;
    for (i = 0; i < l; i++) {
        int FLAG = 0;
        for (j = 0; j < k; j++) {
            if (nums[i] == h[j]) {
                FLAG = 1;
                nums[i] = m+1;
                break;
            }
        }
        if (!FLAG) {
            h[j] = nums[i];
            k++;
        }
    }

    for (i = 0; i < k; i++) nums[i] = h[i];
    for (i = k; i < l; i++) nums[i] = -1;

    return k;
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
  int *nums = malloc(sizeof(int)*3);
  int b1[3] = {1,1,2};

  unsigned int i = 0;
  for (; i < 3; i++) nums[i] = b1[i];
  
  removeDuplicates(nums, 3); // [1,2]

  print(nums, 3);
  free(nums);

  // ***

  nums = malloc(sizeof(int)*10);
  int b2[10] = {0,0,1,1,1,2,2,3,3,4};
  for (i = 0; i < 10; i++) nums[i] = b2[i];
  
  removeDuplicates(nums, 10); // [0,1,2,3,4]

  print(nums, 10);
  free(nums);

  return 0;
}

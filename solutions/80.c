#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int e;
  int c;
} h_t;

int removeDuplicates(int* nums, int numsSize){
  const int l = numsSize;
  h_t h[l];
  unsigned int i = 0, j, k = 0;

  int m = 0;
  for (; i < l; i++) if (m < nums[i]) m = nums[i];

  for (i = 0; i < l; i++) {
    int FLAG = 0;
    for (j = 0; j < k; j++) {
      if (nums[i] == h[j].e) {
        FLAG = 1;
        h[j].c++;
        if (h[j].c > 2) nums[i] = m+1;
        break;
      }
    }
    if (!FLAG) {
      h[j].e = nums[i];
      h[j].c = 1; k++;
    }
  }

  for (i = 0; i < l; i++) {
    for (j = i+1; j < l; j++) {
      if (nums[i] > nums[j]) {
        int t = nums[j];
        nums[j] = nums[i];
        nums[i] = t;
      }
    }
  }

  j = 0;
  for (i = l-1; i > 0; i--) {
    if (nums[i] == m+1) j+=1;
    else break;
  }

  return l-j;
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
  int *nums = malloc(sizeof(int)*6);
  int b1[6] = {1,1,1,2,2,3};

  unsigned int i = 0;
  for (; i < 6; i++) nums[i] = b1[i];
  
  removeDuplicates(nums, 6); // [1,1,2,2,3]

  print(nums, 6);
  free(nums);

  // ***

  nums = malloc(sizeof(int)*9);
  int b2[9] = {0,0,1,1,1,1,2,3,3};
  for (i = 0; i < 9; i++) nums[i] = b2[i];
  
  removeDuplicates(nums, 9); // [0,0,1,1,2,3,3]

  print(nums, 9);
  free(nums);

  return 0;
}

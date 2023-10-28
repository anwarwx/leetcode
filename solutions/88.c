#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
  unsigned int i = m;
  unsigned int j = 0;
  for (; i < nums1Size; i++, j++) nums1[i] = nums2[j];

  int l = nums1Size;
  for (i = 0; i < l; i++) {
    for (j = i+1; j < l; j++) {
      if (nums1[i] > nums1[j]) {
        int t = nums1[j];
        nums1[j] = nums1[i];
        nums1[i] = t;
      }
    }
  }
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
  int *nums1 = malloc(sizeof(int)*6);
  int *nums2 = malloc(sizeof(int)*3);
  
  int b1[6] = {1,2,3,0,0,0};
  int b2[3] = {2, 5, 6};

  unsigned int i = 0;
  unsigned int j = 0;

  for (; i < 6; i++) nums1[i] = b1[i];
  for (; j < 3; j++) nums2[j] = b2[j];
  
  merge(nums1, 6, 3, nums2, 3, 3); // [1,2,2,3,5,6]
  print(nums1,  6);

  free(nums1);
  free(nums2);

  // ***

  nums1 = malloc(sizeof(int)); nums1[0] = 1;
  nums2 = malloc(sizeof(int));

  merge(nums1, 1, 1, nums2, 1, 0); // [1]
  print(nums1,  1);

  // ***

  nums1[0] = 0;
  nums2[0] = 1;

  merge(nums1, 1, 0, nums2, 1, 1); // [1]
  print(nums1, 1);

  free(nums1);
  free(nums2);

  return 0;
}

/* Note: The returned array must be malloced, assume caller calls free(). */

#include <stdlib.h>

int* sumZero(int n, int* returnSize)
{
  int i, j, middle;
  int* nums;

  *returnSize = n;
  nums = (int*) malloc(*returnSize * sizeof(int));
  if (!(n % 2)) {
    middle = n / 2;
    for (i = 0; i < middle; i++) {
      j = i + 1;
      nums[i] = - j;
      nums[i + middle] = j;
    }
  } else {
    middle = (n - 1) / 2;
    nums[middle] = 0;
    for (i = 0; i < middle; i++) {
      j = i + 1;
      nums[i] = - j;
      nums[j + middle] = j;
    }
  }
  return nums;
}

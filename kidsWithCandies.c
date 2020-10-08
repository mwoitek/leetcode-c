/* Note: The returned array must be malloced, assume caller calls free(). */

#include <stdlib.h>
#include <stdbool.h>

int getMax(int* candies, int candiesSize)
{
  int i, max = -1;

  for (i = 0; i < candiesSize; i++) {
    if (candies[i] > max) {
      max = candies[i];
    }
  }
  return max;
}

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize)
{
  int i, max;
  bool* returnedArray;

  max = getMax(candies, candiesSize);
  *returnSize = candiesSize;
  returnedArray = (bool*) malloc(*returnSize * sizeof(bool));
  for (i = 0; i < candiesSize; i++) {
    if (candies[i] + extraCandies < max) {
      returnedArray[i] = false;
    } else {
      returnedArray[i] = true;
    }
  }
  return returnedArray;
}

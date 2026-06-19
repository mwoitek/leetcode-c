/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* rearrangeArray(int* nums, int numsSize, int* returnSize)
{
  int n = numsSize / 2;
  int* pos = (int*)calloc(n, sizeof(int));
  int* neg = (int*)calloc(n, sizeof(int));

  int i = 0;
  int j = 0;

  for (int k = 0; k < numsSize; k++) {
    if (nums[k] > 0)
      pos[i++] = nums[k];
    else
      neg[j++] = nums[k];
  }

  i = 0;
  j = 0;

  for (int k = 0; k < numsSize; k += 2) {
    nums[k] = pos[i++];
    nums[k + 1] = neg[j++];
  }

  free(pos);
  free(neg);

  *returnSize = numsSize;
  return nums;
}

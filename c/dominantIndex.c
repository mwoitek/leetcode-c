int findIndexMaximum(int* nums, int numsSize)
{
  int i;
  int indexMaximum;
  int maximum = -1;

  for (i = 0; i < numsSize; i++) {
    if (nums[i] > maximum) {
      maximum = nums[i];
      indexMaximum = i;
    }
  }
  return indexMaximum;
}

int dominantIndex(int* nums, int numsSize)
{
  int i;
  int indexMaximum;
  int maximum;

  indexMaximum = findIndexMaximum(nums, numsSize);
  maximum = nums[indexMaximum];
  for (i = 0; i < numsSize; i++) {
    if ((i != indexMaximum) && (2 * nums[i] > maximum)) {
      return -1;
    }
  }
  return indexMaximum;
}

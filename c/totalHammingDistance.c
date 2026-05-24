int totalHammingDistance(int* nums, int numsSize)
{
    int i, j, temp, total = 0;

    for (i = 0; i < numsSize - 1; i++) {
        temp = nums[i];
        for (j = i + 1; j < numsSize; j++) {
            total += __builtin_popcount(temp ^ nums[j]);
        }
    }
    return total;
}

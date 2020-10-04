int missingNumber(int* nums, int numsSize)
{
    int i, N = numsSize + 1;
    int occurr[N];

    for (i = 0; i < N; i++) {
        occurr[i] = 0;
    }
    for (i = 0; i < numsSize; i++) {
        occurr[nums[i]] += 1;
    }
    i = 0;
    while (occurr[i]) {
        i++;
    }
    return i;
}

void swap(int* a, int* b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

int findKthLargest(int* nums, int numsSize, int k)
{
    int i, j, temp;

    for (i = 0; i < k; i++) {
        for (j = 0; j < numsSize - i - 1; j++) {
            temp = j + 1;
            if (nums[j] > nums[temp]) {
                swap(&nums[j], &nums[temp]);
            }
        }
    }
    return nums[numsSize - k];
}

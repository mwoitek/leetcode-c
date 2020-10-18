int findPeakElement(int* nums, int numsSize)
{
    int left = 0;
    int middle;
    int right = numsSize - 1;
    int temp;

    while (left < right) {
        middle = left + (right - left) / 2;
        temp = middle + 1;
        if (nums[middle] > nums[temp]) {
            right = middle;
        } else {
            left = temp;
        }
    }
    return left;
}

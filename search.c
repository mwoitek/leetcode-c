int search(int* nums, int numsSize, int target)
{
    int left = 0;
    int middle;
    int right = numsSize - 1;
    int temp;

    while (left <= right) {
        middle = left + (right - left) / 2;
        temp = nums[middle];
        if (temp < target) {
            left = middle + 1;
        } else if (temp > target) {
            right = middle - 1;
        } else {
            return middle;
        }
    }
    return -1;
}

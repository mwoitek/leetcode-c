int search(int* nums, int numsSize, int target)
{
    if (!numsSize) { return -1; }

    int left = 0;
    int middle;
    int right = numsSize - 1;
    int temp;

    while (left < right) {
        middle = left + (right - left) / 2;
        if (nums[middle] > nums[right]) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }

    right = numsSize - 1;
    if ((target < nums[left]) || (target > nums[right])) {
        right = left - 1;
        left = 0;
    }

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

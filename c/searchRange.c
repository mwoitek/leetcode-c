/* Note: The returned array must be malloced, assume caller calls free(). */

#include <stdlib.h>

int lowerBound(int* nums, int numsSize, int target)
{
    int index = numsSize;
    int left = 0;
    int middle;
    int right = numsSize - 1;

    while (left <= right) {
        middle = left + (right - left) / 2;
        if (nums[middle] >= target) {
            index = middle;
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    return index;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize = 2;
    int* answer = (int*) malloc(*returnSize * sizeof(int));
    answer[0] = -1;
    answer[1] = -1;
    if (!numsSize) { return answer; }

    int first = lowerBound(nums, numsSize, target);
    if ((first == numsSize) || (nums[first] != target)) { return answer; }

    int last = lowerBound(nums, numsSize, target + 1) - 1;
    answer[0] = first;
    answer[1] = last;
    return answer;
}

bool checkPossibility(int* nums, int numsSize)
{
    int count = 0, i;

    for (i = 1; i < numsSize; i++) {
        if (nums[i] < nums[i - 1]) {
            count++;
            if (count == 1) {
                if (i == 1 || nums[i] >= nums[i - 2]) {
                    continue;
                } else if (i == numsSize - 1 || nums[i + 1] >= nums[i - 1]) {
                    continue;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
    }
    return true;
}

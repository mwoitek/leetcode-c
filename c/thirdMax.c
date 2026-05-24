#define CONST_K 3

void swap(int* a, int* b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

int thirdMax(int* nums, int numsSize)
{
    int i, j, k, last_max, Li, max, temp;
    int L = numsSize - 1;

    for (j = 0; j < L; j++) {
        temp = j + 1;
        if (nums[j] > nums[temp]) {
            swap(&nums[j], &nums[temp]);
        }
    }
    max = nums[L];
    if (numsSize < CONST_K) {
        return max;
    }
    k = 1;
    last_max = max;
    for (i = 1; i < numsSize; i++) {
        Li = L - i;
        for (j = 0; j < Li; j++) {
            temp = j + 1;
            if (nums[j] > nums[temp]) {
                swap(&nums[j], &nums[temp]);
            }
        }
        if (nums[Li] != last_max) {
            last_max = nums[Li];
            if (++k == CONST_K) {
                break;
            }
        }
    }
    if (k < CONST_K) {
        return max;
    } else {
        return last_max;
    }
}

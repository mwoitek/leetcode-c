void swap(int* a, int* b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

int maximumProduct(int* nums, int numsSize)
{
    int i, j, j1, Li, max, max_prod, min, prod, prods[4], prod_2_max, prod_2_min;
    int L = numsSize - 1;

    for (i = 0; i < 3; i++) {
        Li = L - i;
        for (j = 0; j < Li; j++) {
            j1 = j + 1;
            if (nums[j] > nums[j1]) {
                swap(&nums[j], &nums[j1]);
            }
        }
    }
    max = nums[L];
    prod_2_max = max * nums[L - 1];
    prods[0] = nums[L - 2] * prod_2_max;
    for (i = 0; i < 3; i++) {
        Li = L - i;
        for (j = 0; j < Li; j++) {
            j1 = j + 1;
            if (nums[j] < nums[j1]) {
                swap(&nums[j], &nums[j1]);
            }
        }
    }
    min = nums[L];
    prod_2_min = min * nums[L - 1];
    prods[1] = nums[L - 2] * prod_2_min;
    prods[2] = min * prod_2_max;
    prods[3] = max * prod_2_min;
    max_prod = prods[0];
    for (i = 1; i < 4; i++) {
        prod = prods[i];
        if (prod > max_prod) {
            max_prod = prod;
        }
    }
    return max_prod;
}

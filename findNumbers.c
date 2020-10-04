int findNumbers(int* nums, int numsSize)
{
    int count = 0;
    int i;
    char temp_str[7];

    for (i = 0; i < numsSize; i++) {
        sprintf(temp_str, "%d", nums[i]);
        count += !(strlen(temp_str) % 2);
    }
    return count;
}

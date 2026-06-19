#include <stdio.h>
#include <stdlib.h>

#include "glib.h"

int reverseDigits(int num)
{
  if (num < 10) return num;

  GArray* digits = g_array_new(FALSE, FALSE, sizeof(int));
  while (num > 0) {
    int digit = num % 10;
    g_array_append_val(digits, digit);
    num /= 10;
  }

  int reversed = 0;
  int power10 = 1;
  for (int i = digits->len; i > 0; i--) {
    reversed += power10 * g_array_index(digits, int, i - 1);
    power10 *= 10;
  }

  g_array_free(digits, TRUE);
  return reversed;
}

int countDistinctIntegers(int* nums, int numsSize)
{
  int* reversed = (int*)calloc(numsSize, sizeof(int));
  for (int i = 0; i < numsSize; i++) {
    reversed[i] = reverseDigits(nums[i]);
  }

  GHashTable* set = g_hash_table_new(g_int_hash, g_int_equal);
  for (int i = 0; i < numsSize; i++) {
    g_hash_table_add(set, nums + i);
    g_hash_table_add(set, reversed + i);
  }
  int cnt = g_hash_table_size(set);

  g_hash_table_destroy(set);
  free(reversed);

  return cnt;
}

int main(void)
{
  // int num = 1234;
  // int reversed = reverseDigits(num);
  // printf("%d -> %d\n", num, reversed);

  int nums1[] = {1, 13, 10, 12, 31};
  int cnt1 = countDistinctIntegers(nums1, 5);
  printf("Case 1 -> Answer: %d\n", cnt1);

  int nums2[] = {2, 2, 2};
  int cnt2 = countDistinctIntegers(nums2, 3);
  printf("Case 2 -> Answer: %d\n", cnt2);

  return 0;
}

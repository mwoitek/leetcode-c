#include <stdio.h>
#include <stdlib.h>
#include <uthash.h>

typedef struct {
  int key;
  int val;
  UT_hash_handle hh;
} Entry;

int sortByCount(Entry* a, Entry* b)
{
  if (a->val == b->val) return 0;
  return a->val > b->val ? -1 : 1;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize)
{
  Entry* table = NULL;
  Entry* e = NULL;

  for (int i = 0; i < numsSize; i++) {
    e = NULL;
    HASH_FIND_INT(table, nums + i, e);
    if (e) {
      e->val++;
      continue;
    }
    e = malloc(sizeof(*e));
    e->key = nums[i];
    e->val = 1;
    HASH_ADD_INT(table, key, e);
  }

  HASH_SRT(hh, table, sortByCount);

  *returnSize = k;
  int* ans = (int*)calloc(k, sizeof(int));

  e = NULL;
  Entry* tmp = NULL;
  int i = 0;

  HASH_ITER(hh, table, e, tmp)
  {
    if (i < k) ans[i++] = e->key;
    HASH_DEL(table, e);
    free(e);
  }

  return ans;
}

int main(void)
{
  int returnSize;

  int nums1[] = {1, 1, 1, 2, 2, 3};
  int numsSize1 = 6;
  int k1 = 2;
  int* ans1 = topKFrequent(nums1, numsSize1, k1, &returnSize);
  printf("Case 1: ");
  for (int i = 0; i < k1; i++) printf("%d ", ans1[i]);
  printf("\n");
  free(ans1);

  int nums2[] = {1};
  int numsSize2 = 1;
  int k2 = 1;
  int* ans2 = topKFrequent(nums2, numsSize2, k2, &returnSize);
  printf("Case 2: ");
  for (int i = 0; i < k2; i++) printf("%d ", ans2[i]);
  printf("\n");
  free(ans2);

  int nums3[] = {1, 2, 1, 2, 1, 2, 3, 1, 3, 2};
  int numsSize3 = 10;
  int k3 = 2;
  int* ans3 = topKFrequent(nums3, numsSize3, k3, &returnSize);
  printf("Case 3: ");
  for (int i = 0; i < k3; i++) printf("%d ", ans3[i]);
  printf("\n");
  free(ans3);

  return 0;
}

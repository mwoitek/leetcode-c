#include <stdio.h>
#include <stdlib.h>
#include <uthash.h>

typedef struct {
  char key;
  int val;
  UT_hash_handle hh;
} Entry;

int firstUniqChar(char* s)
{
  Entry* table = NULL;
  Entry* e = NULL;

  for (const char* p = s; *p; p++) {
    e = NULL;
    HASH_FIND(hh, table, p, sizeof(char), e);
    if (e) {
      e->val++;
      continue;
    }
    e = malloc(sizeof(*e));
    e->key = *p;
    e->val = 1;
    HASH_ADD(hh, table, key, sizeof(char), e);
  }

  int i = 0;
  for (const char* p = s; *p; p++) {
    e = NULL;
    HASH_FIND(hh, table, p, sizeof(char), e);
    if (e != NULL && e->val == 1) break;
    i++;
  }
  if (s[i] == '\0') i = -1;

  Entry* tmp = NULL;
  HASH_ITER(hh, table, e, tmp)
  {
    HASH_DEL(table, e);
    free(e);
  }

  return i;
}

int main(void)
{
  char* s1 = "leetcode";
  int ans1 = firstUniqChar(s1);
  printf("Case 1: %s -> %d\n", s1, ans1);

  char* s2 = "loveleetcode";
  int ans2 = firstUniqChar(s2);
  printf("Case 2: %s -> %d\n", s2, ans2);

  char* s3 = "aabb";
  int ans3 = firstUniqChar(s3);
  printf("Case 3: %s -> %d\n", s3, ans3);

  return 0;
}

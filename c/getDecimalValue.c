/*
 * Definition for singly-linked list:
 * struct ListNode {
 *     int val;
 *     struct ListNode* next;
 * };
 */

#include <math.h>

int countNodes(struct ListNode* head)
{
  int count = 0;
  struct ListNode* current = head;

  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

int getDecimalValue(struct ListNode* head)
{
  struct ListNode* current = head;
  int decimalValue = 0;
  int i;
  int numberNodes;
  int powerOfTwo;

  numberNodes = countNodes(head);
  for (i = numberNodes - 1; i >= 0; i--) {
    powerOfTwo = (int) pow(2.0, (double) i);
    decimalValue += powerOfTwo * current->val;
    current = current->next;
  }
  return decimalValue;
}

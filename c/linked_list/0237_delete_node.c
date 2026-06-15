/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node)
{
  struct ListNode* prev = NULL;
  struct ListNode* curr = node;
  while (curr->next) {
    int tmp = curr->val;
    curr->val = curr->next->val;
    curr->next->val = tmp;
    prev = curr;
    curr = curr->next;
  }
  prev->next = NULL;
  free(curr);
}

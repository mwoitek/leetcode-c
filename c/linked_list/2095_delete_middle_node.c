/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head)
{
  struct ListNode* slow = head;
  // With the dummy, the list is guaranteed to have at least 2 nodes
  struct ListNode* fast = head->next;
  while (fast) {
    fast = fast->next;
    if (!fast) break;
    slow = slow->next;
    fast = fast->next;
  }
  return slow;
}

struct ListNode* deleteMiddle(struct ListNode* head)
{
  struct ListNode dummy = {0, head};
  struct ListNode* middlePrev = middleNode(&dummy);
  struct ListNode* middle = middlePrev->next;
  middlePrev->next = middle->next;
  free(middle);
  head = dummy.next;
  return head;
}

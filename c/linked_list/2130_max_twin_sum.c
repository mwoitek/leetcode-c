/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head)
{
  // Assumptions: List is non-empty, and it has an even number of nodes.
  struct ListNode* slow = head;
  struct ListNode* fast = head->next->next;
  while (fast != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

struct ListNode* reverseList(struct ListNode* head)
{
  struct ListNode* prev = NULL;
  struct ListNode* curr = head;
  while (curr != NULL) {
    struct ListNode* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

int pairSum(struct ListNode* head)
{
  int maxSum = 0;

  struct ListNode* middle = middleNode(head);
  struct ListNode* reversed = reverseList(middle->next);
  middle->next = reversed;

  struct ListNode* p1 = head;
  struct ListNode* p2 = reversed;

  while (p2 != NULL) {
    int sum = p1->val + p2->val;
    if (sum > maxSum) maxSum = sum;
    p1 = p1->next;
    p2 = p2->next;
  }

  return maxSum;
}

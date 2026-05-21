/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
  ListNode* removeNthFromEnd(ListNode* head, int n)
  {
    // get list length
    auto p1 = head;
    int l = 0;
    while (p1 != nullptr) {
      l++;
      p1 = p1->next;
    }

    // 1-based index of the node that needs to be removed
    int i = l - n + 1;

    // handle the case where the first node has to be removed
    if (i == 1) {
      auto p2 = head->next;
      delete head;
      return p2;
    }

    // get to the predecessor of the node that needs to be removed
    p1 = head;
    int j = 1;
    while (j < i - 1) {
      j++;
      p1 = p1->next;
    }

    // remove the target node
    auto p2 = p1->next;
    p1->next = p2->next;
    delete p2;
    return head;
  }
};

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
  ListNode* deleteDuplicates(ListNode* head)
  {
    if (!head) return head;

    // it is possible to use less moving parts, but this is good enough
    auto d = new ListNode(-1, head);
    auto p = d;
    auto n1 = head;
    auto n2 = head->next;

    while (n1) {
      int i = 1;
      while (n2 && n1->val == n2->val) {
        n2 = n2->next;
        i++;
      }
      if (i == 1) {
        p = n1;
        n1 = n2;
        if (n2) n2 = n2->next;
        continue;
      }
      p->next = n2;
      while (n1 != n2) {
        auto t = n1->next;
        delete n1;
        n1 = t;
      }
      if (n2) n2 = n2->next;
    }

    auto ans = d->next;
    delete d;
    return ans;
  }
};

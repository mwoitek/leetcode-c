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
  ListNode* reverse_list(ListNode* l)
  {
    ListNode* p = nullptr;
    auto c = l;
    while (c != nullptr) {
      auto n = c->next;
      c->next = p;
      p = c;
      c = n;
    }
    return p;
  }

  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
  {
    auto r1 = reverse_list(l1);
    auto r2 = reverse_list(l2);

    auto s = r1->val + r2->val;
    auto c = s / 10;
    r1 = r1->next;
    r2 = r2->next;

    auto l = new ListNode(s % 10);
    auto n = l;

    while (r1 != nullptr && r2 != nullptr) {
      s = r1->val + r2->val + c;
      c = s / 10;
      r1 = r1->next;
      r2 = r2->next;
      n->next = new ListNode(s % 10);
      n = n->next;
    }

    auto p = r1 == nullptr ? r2 : r1;
    while (p != nullptr) {
      s = p->val + c;
      c = s / 10;
      p = p->next;
      n->next = new ListNode(s % 10);
      n = n->next;
    }

    if (c) n->next = new ListNode(c);
    return reverse_list(l);
  }
};

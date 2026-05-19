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
  ListNode* reverseBetween(ListNode* head, int left, int right)
  {
    auto n = head;
    int i = 1;

    while (i < left) {
      n = n->next;
      i++;
    }
    auto nl = n;

    while (i <= right) {
      n = n->next;
      i++;
    }
    auto nr = n;

    int l = right - left + 1;
    auto vals = vector<int>(l);

    n = nl;
    int j = 0;
    while (n != nr) {
      vals[j++] = n->val;
      n = n->next;
    }

    n = nl;
    j = l - 1;
    while (n != nr) {
      n->val = vals[j--];
      n = n->next;
    }

    return head;
  }
};

#include <stddef.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int carry = 0;
    int sum;
    struct ListNode* head;
    struct ListNode* l3;

    head = (struct ListNode*) malloc(sizeof(struct ListNode));
    l3 = head;
    while ((l1 != NULL) || (l2 != NULL)) {
        sum = (l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0) + carry;
        l3->next = (struct ListNode*) malloc(sizeof(struct ListNode));
        l3->next->val = sum % 10;
        carry = sum / 10;
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
        l3 = l3->next;
    }
    if (carry) {
        l3->next = (struct ListNode*) malloc(sizeof(struct ListNode));
        l3->next->val = carry;
        l3 = l3->next;
    }
    l3->next = NULL;
    return head->next;
}

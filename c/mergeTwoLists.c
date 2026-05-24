#include <stddef.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* fakeHead = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* l3 = fakeHead;

    while ((l1 != NULL) && (l2 != NULL)) {
        if (l1->val < l2->val) {
            l3->next = l1;
            l1 = l1->next;
        } else {
            l3->next = l2;
            l2 = l2->next;
        }
        l3 = l3->next;
    }
    l3->next = l1 != NULL ? l1 : l2;
    return fakeHead->next;
}

#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* node1 = head;
    struct ListNode* node2 = head;

    while (node2 != NULL) {
        node2 = node2->next;
        if (node2 == NULL) { break; }
        node1 = node1->next;
        node2 = node2->next;
    }
    return node1;
}

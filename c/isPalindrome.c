#include <stdbool.h>
#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* next;
    struct ListNode* prev = NULL;

    while (head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head)
{
    struct ListNode* node1 = head;
    struct ListNode* node2 = head;

    while ((node2 != NULL) && (node2->next != NULL)) {
        node1 = node1->next;
        node2 = node2->next->next;
    }
    node1 = reverseList(node1);
    node2 = head;
    while (node1 != NULL) {
        if (node1->val != node2->val) { return false; }
        node1 = node1->next;
        node2 = node2->next;
    }
    return true;
}

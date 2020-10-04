/*
 * Definition for singly-linked list:
 * struct ListNode
 * {
 *     int val;
 *     struct ListNode* next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* current = head;
    struct ListNode* current_next;
    struct ListNode* previous = NULL;

    while (current != NULL) {
        current_next = current->next;
        if (current->val == val) {
            free(current);
            if (previous == NULL) {
                head = current_next;
                previous = NULL;
            } else {
                previous->next = current_next;
            }
        } else {
            previous = current;
        }
        current = current_next;
    }
    return head;
}

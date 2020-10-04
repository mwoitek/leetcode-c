/*
 * Definition for singly-linked list:
 * struct ListNode
 * {
 *     int val;
 *     struct ListNode* next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode* current = head;
    struct ListNode* next_next;

    if (current != NULL) {
        while (current->next != NULL) {
            if (current->val == current->next->val) {
                next_next = current->next->next;
                free(current->next);
                current->next = next_next;
            } else {
                current = current->next;
            }
        }
    }
    return head;
}

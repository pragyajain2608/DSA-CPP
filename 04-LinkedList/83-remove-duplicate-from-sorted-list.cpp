/*
Problem: LeetCode 83 - Remove Duplicates from Sorted List

Approach: Single Pointer Traversal

Time Complexity: O(n)
Space Complexity: O(1)

Initialize a pointer temp at the head and traverse the
sorted linked list.

If the current node and its next node have the same value,
skip the duplicate node by updating temp->next.

Otherwise, move temp to the next node.

Continue until temp or temp->next becomes NULL.

Since the list is sorted, duplicates appear consecutively,
so they can be removed in a single traversal.
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;

        while(temp != NULL && temp->next != NULL) {
            if(temp->val == temp->next->val) {
                temp->next = temp->next->next;
            }
            else {
                temp = temp->next;
            }
        }

        return head;
    }
};

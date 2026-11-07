/*
Problem: LeetCode 141 - Linked List Cycle

Approach: Floyd's Cycle Detection Algorithm (Slow and Fast Pointers)

Time Complexity: O(n)
Space Complexity: O(1)

Initialize slow and fast pointers at the head.
Move slow one step and fast two steps at a time.

If a cycle exists, both pointers will eventually meet.
If fast reaches NULL or fast->next becomes NULL,
the linked list has no cycle.

Return true if they meet, otherwise return false.
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};

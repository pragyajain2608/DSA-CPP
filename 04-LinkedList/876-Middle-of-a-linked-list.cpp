/*
Problem: LeetCode 876 - Middle of the Linked List

Approach: Slow and Fast Pointer

Time Complexity: O(n)
Space Complexity: O(1)

The slow pointer moves one step while the fast pointer
moves two steps. When fast reaches the end, slow is
at the middle node.
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};

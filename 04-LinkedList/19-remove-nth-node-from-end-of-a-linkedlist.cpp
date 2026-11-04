/*
Problem: LeetCode 19 - Remove Nth Node From End of List

Approach: Two Pointers (Slow and Fast)

Time Complexity: O(n)
Space Complexity: O(1)

Move the fast pointer n+1 steps ahead to maintain a gap
between slow and fast pointers.

Then move both pointers simultaneously until fast reaches
NULL. The slow pointer will be just before the node to be
removed.

If fast becomes NULL during the initial traversal, remove
the head node.
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast=head;
        for(int i=1;i<=n+1;i++){
            if(fast==NULL) return head->next;
            fast=fast->next;
        }
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};

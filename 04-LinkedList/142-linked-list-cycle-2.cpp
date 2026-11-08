/*
Problem: LeetCode 142 - Linked List Cycle II

Approach: Floyd's Cycle Detection Algorithm (Slow and Fast Pointers)

Time Complexity: O(n)
Space Complexity: O(1)

Initialize slow and fast pointers at the head.
Move slow one step and fast two steps at a time.

If they meet, a cycle exists. Reset another pointer to
the head and move both pointers one step at a time.

The point where they meet again is the starting node
of the cycle.

If no meeting occurs, return NULL.
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        bool flag=false;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                flag=true;
                break;
            }
        }
        if(flag==NULL) return NULL;
        else{
            ListNode* temp=head;
            while(temp!=slow){
                temp=temp->next;
                slow=slow->next;
            }
            return slow;
        }
    }
};

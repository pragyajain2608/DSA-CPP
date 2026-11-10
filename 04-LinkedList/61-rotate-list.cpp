/*
Problem: LeetCode 61 - Rotate List

Approach: Length Calculation + Pointer Manipulation

Time Complexity: O(n)
Space Complexity: O(1)

First, traverse the linked list to calculate its length
and find the tail node.

Calculate k = k % n to avoid unnecessary rotations.

If k becomes 0, return the original list.

Find the new tail at position (n-k) from the beginning.
Connect the original tail to the head to form a circular
linked list.

Set the new head as temp->next and break the circle
by updating temp->next = NULL.

Return the new head.
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head;
        ListNode* tail=NULL;
        int n=0;
        while(temp!=NULL){
            if(temp->next==NULL) tail=temp;
            temp=temp->next;
            n++;
        }
        k=k%n;
        if(k==0) return head;
        temp=head;
        for(int i=1;i<n-k;i++){
            temp=temp->next;
        }
        tail->next=head;
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};

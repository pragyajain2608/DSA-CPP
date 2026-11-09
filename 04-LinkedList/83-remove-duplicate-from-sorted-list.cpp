/*
Problem: LeetCode 83 - Remove Duplicates from Sorted List

Approach: Two Pointers (a and b)

Time Complexity: O(n)
Space Complexity: O(1)

Initialize two pointers: a at head and b at head->next.

Traverse the sorted linked list using b.
If b->val is equal to a->val, move b ahead to skip
the duplicate nodes.

When a different value is found, connect a->next to b
and move a to b.

Continue until b reaches NULL. Return the updated head.

Since the list is sorted, duplicate elements appear
consecutively and can be removed in a single traversal.
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* a=head;
        ListNode* b=head->next;
        while(b!=NULL){
            while(b!=NULL && b->val==a->val){
                b=b->next;
            }
            a->next=b;
            a=b;                         //for next round
            if(b!=NULL) b=b->next;
        }
        return head;
    }
};

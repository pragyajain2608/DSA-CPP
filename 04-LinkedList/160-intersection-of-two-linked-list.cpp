/*
Problem: LeetCode 160 - Intersection of Two Linked Lists

Approach: Length Difference (Two Pointers)

Time Complexity: O(n + m)
Space Complexity: O(1)

First, calculate the lengths of both linked lists.
Move the pointer of the longer list ahead by the
difference in their lengths.

Now both pointers have the same remaining distance
to travel. Move them simultaneously until they meet.

If they meet, return the intersection node;
otherwise, return NULL.
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=0;
        int lenB=0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(tempA!=NULL){
            tempA=tempA->next;
            lenA++;
        }
        while(tempB!=NULL){
            tempB=tempB->next;
            lenB++;
        }
        tempA=headA;
        tempB=headB;
        if(lenA>lenB){
            int diff=lenA-lenB;
            for(int i=0;i<diff;i++){
                tempA=tempA->next;
            }
        }
        else{
            int diff=lenB-lenA;
            for(int i=0;i<diff;i++){
                tempB=tempB->next;
            }
        }
        while(tempA!=tempB){
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return tempA;
    }
};

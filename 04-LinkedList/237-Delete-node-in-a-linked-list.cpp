/*
Problem: LeetCode 237 - Delete Node in a Linked List

Approach:
1. Copy the next node's value into the current node.
2. Skip the next node by updating the next pointer.

Time Complexity: O(1)
Space Complexity: O(1)

Note: The given node is guaranteed not to be the last node.
*/
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
        }
};
int main() {

    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    Solution obj;

    obj.deleteNode(head->next);

    ListNode* temp = head;

    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}
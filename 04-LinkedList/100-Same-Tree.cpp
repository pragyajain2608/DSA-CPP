/*
Problem: LeetCode 100 - Same Tree

Approach: Recursion (Depth First Search)

Time Complexity: O(n)
Space Complexity: O(h)

First, check the base cases:
- If both nodes are NULL, return true.
- If only one node is NULL, return false.
- If node values are different, return false.

Recursively compare the left subtrees of both trees.
If they are not same, return false.

Similarly, compare the right subtrees.

If both left and right subtrees are identical and
the current node values match, return true.

The trees are identical only if their structure
and corresponding node values are the same.
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        if(p->val != q->val) return false;
        bool leftans=isSameTree(p->left,q->left);
        if(leftans == false) return false;
        bool rightans=isSameTree(p->right,q->right);
        if(rightans == false) return false;
        return true;
    }
};

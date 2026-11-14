/*
Problem: LeetCode 226 - Invert Binary Tree

Approach: Recursion (Depth First Search)

Time Complexity: O(n)
Space Complexity: O(h)

Traverse the binary tree recursively.

At each node, swap its left and right child pointers
using a temporary pointer.

Then recursively invert the left and right subtrees.

Continue until all nodes have been visited.

Return the root of the inverted tree.
*/
class Solution {
public:
void helper(TreeNode* root){
    if(root==NULL) return;
    TreeNode* temp=root->left;
    root->left=root->right;
    root->right=temp;
    helper(root->left);
    helper(root->right);
}
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};

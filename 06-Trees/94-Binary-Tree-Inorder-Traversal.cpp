/*
Problem: LeetCode 94 - Binary Tree Inorder Traversal

Approach: Recursion (Left → Root → Right)

Time Complexity: O(n)
Space Complexity: O(h) - Auxiliary recursion space (excluding output)

Traverse the binary tree using inorder traversal.

First, recursively traverse the left subtree.

Then visit the root node and store its value in the vector.

Finally, recursively traverse the right subtree.

Continue until all nodes have been visited.

Return the vector containing the inorder traversal.
*/
class Solution {
public:
    void inorder(TreeNode* root,vector<int> &v){
        if(root==NULL) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        return v;
    }
};

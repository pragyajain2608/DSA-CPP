/*
Problem: LeetCode 144 - Binary Tree Preorder Traversal

Approach: Recursion (Root → Left → Right)

Time Complexity: O(n)
Space Complexity: O(h) - Auxiliary recursion space (excluding output)

Traverse the binary tree using preorder traversal.

First, visit the root node and store its value in the vector.

Then recursively traverse the left subtree followed by
the right subtree.

Continue until all nodes have been visited.

Return the vector containing the preorder traversal.
*/
class Solution {
public:
    void preorder(TreeNode* root,vector<int> &v){
        if(root==NULL) return;
        v.push_back(root->val);
        preorder(root->left,v);
        preorder(root->right,v);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        preorder(root,v);
        return v;
    }
};

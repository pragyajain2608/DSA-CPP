/*
Problem: LeetCode 102 - Binary Tree Level Order Traversal

Approach: Recursion (Level-wise Traversal)

Time Complexity: O(n^2)
Space Complexity: O(h) - Auxiliary recursion space (excluding output)

First, calculate the height of the binary tree using
the levels() function.

Iterate through each level from 1 to n.

For every level, call nthlevel() to traverse the tree
and collect all nodes present at that particular level.

Store the collected nodes in a separate vector and
add it to the answer.

Continue until all levels have been traversed.

Return the 2D vector containing the level order traversal.
*/
class Solution {
public:
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    void nthlevel(TreeNode* root,int curr,int level,vector<int> &v){
        if(root==NULL) return;
        if(curr==level){
            v.push_back(root->val);
            return;
        }
        nthlevel(root->left,curr+1,level,v);
        nthlevel(root->right,curr+1,level,v);
    }
    void levelorder(TreeNode* root,vector<vector<int>> &ans){
        int n=levels(root);
        for(int i=1;i<=n;i++){
            vector<int> v;
            nthlevel(root,1,i,v);
            ans.push_back(v);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelorder(root,ans);
        return ans;
    }
};

/*
Problem: LeetCode 103 - Binary Tree Zigzag Level Order Traversal

Approach: Recursion (Level-wise Traversal + Zigzag Order)

Time Complexity: O(n^2)
Space Complexity: O(h) - Auxiliary recursion space (excluding output)

First, calculate the height of the binary tree using
the levels() function.

Traverse the tree level by level using nthlevel().

For odd levels, traverse from left to right (Left → Right).
For even levels, traverse from right to left (Right → Left).

At each level, collect the node values in a vector
and add it to the answer.

Continue until all levels have been traversed.

Return the 2D vector containing the zigzag traversal.
*/
class Solution {
public:
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    void nthlevel(TreeNode* root,int level,int curr,vector<int> &v){
        if(root==NULL) return;
        if(curr==level){
            v.push_back(root->val);
            return;
        }
        if(level%2!=0){
            nthlevel(root->left,level,curr+1,v);
            nthlevel(root->right,level,curr+1,v);
        }
        else{
            nthlevel(root->right,level,curr+1,v);
            nthlevel(root->left,level,curr+1,v);
        }
    }
    void levelorder(TreeNode* root,vector<vector<int>> &ans){
        int n=levels(root);
        for(int i=1;i<=n;i++){
            vector<int> v;
            nthlevel(root,i,1,v);
            ans.push_back(v);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelorder(root,ans);
        return ans;
    }
};

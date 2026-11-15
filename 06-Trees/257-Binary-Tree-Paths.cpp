/*
Problem: LeetCode 257 - Binary Tree Paths

Approach: Recursion (Depth First Search)

Time Complexity: O(n * h)
Space Complexity: O(h) - Auxiliary recursion space (excluding output)

Traverse the binary tree recursively while maintaining
a string representing the current path.

At each node, convert its value to a string and append
it to the current path.

If the current node is a leaf node (both children are NULL),
add the complete path to the answer vector.

Otherwise, recursively traverse the left and right subtrees,
adding "->" between consecutive node values.

Return the vector containing all root-to-leaf paths.
*/
class Solution {
public:
    void helper(TreeNode* root,string s,vector<string> &ans){
        if(root==NULL) return;
        string a=to_string(root->val);
        if(root->left ==NULL && root->right==NULL){
            s+=a;
            ans.push_back(s);
            return;
        }
        helper(root->left,s+a+"->",ans);
        helper(root->right,s+a+"->",ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root,"",ans);
        return ans;
    }
};

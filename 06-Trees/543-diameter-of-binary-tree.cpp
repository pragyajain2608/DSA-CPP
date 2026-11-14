/*
Problem: LeetCode 543 - Diameter of Binary Tree

Approach: Optimized Recursion (Single DFS Traversal)

Time Complexity: O(n)
Space Complexity: O(h)

Use a helper function to calculate the height of each
subtree while simultaneously updating the maximum diameter.

Recursively calculate the left and right subtree heights.

At each node, calculate the diameter as left + right
and update maxdia if a larger diameter is found.

Return 1 + max(left, right) to calculate the current
node's height and pass it to its parent.

Use maxdia (passed by reference) to maintain the maximum
diameter throughout the traversal.
*/
class Solution {
public:
    int helper(TreeNode* root, int &maxdia) {
        if(root == NULL) return 0;

        int left = helper(root->left, maxdia);
        int right = helper(root->right, maxdia);

        maxdia = max(maxdia, left + right);

        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxdia=0;
        helper(root,maxdia);
        return maxdia;
    }
};

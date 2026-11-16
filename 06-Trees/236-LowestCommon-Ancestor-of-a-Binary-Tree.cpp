/*
Problem: LeetCode 236 - Lowest Common Ancestor of a Binary Tree

Approach: Recursion (Depth First Search)

Time Complexity: O(n)
Space Complexity: O(h)

If the current root is NULL or matches either p or q,
return the current root.

Recursively search for p and q in the left and right
subtrees.

If the left subtree returns NULL, return the right result.
If the right subtree returns NULL, return the left result.

If both sides return non-NULL, the current root is the
Lowest Common Ancestor (LCA).

Return the root as the LCA.
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == NULL || root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left == NULL) return right;
        if(right == NULL) return left;

        return root;
    }
};

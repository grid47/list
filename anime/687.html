/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int maxi;
public:
    int longestUnivaluePath(TreeNode* root) {
        maxi = 0;
        if((root == NULL) || (root->left == NULL && root->right == NULL)  )
        return 0;
        dfs(root);
        return maxi;
    }

    int dfs(TreeNode *root) {
        if(root == NULL) return 0;
        int l = 0, r = 0;
        int lft = dfs(root->left);
        int rgt = dfs(root->right);
        if((root->left != NULL) && (root->left->val == root->val))
        l = lft;
        if((root->right != NULL) && (root->right->val == root->val))
        r = rgt;        

        maxi = max(maxi, l + r);
        return 1 + max(l, r);
    }
};
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
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        dep(d, root);
        return d;
    }
    
    int dep(int &d, TreeNode* node) {
        if(node == NULL) return 0;
        int l = dep(d, node->left);
        int r = dep(d, node->right);
        d = max(d, l + r);
        return 1 + max(l, r);
    }
};
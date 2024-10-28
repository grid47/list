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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return lcadn(root).first;
    }

    pair<TreeNode*, int> lcadn(TreeNode* root) {
        if(root == NULL) return {NULL, 0};
        auto lft = lcadn(root->left);
        auto rht = lcadn(root->right);
        if(lft.second < rht.second) {
            return {rht.first, rht.second + 1};
        } else if (lft.second > rht.second) {
            return {lft.first, lft.second + 1};            
        }
        return {root, lft.second + 1};
    }
};
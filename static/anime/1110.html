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
    vector<TreeNode*> ans;
    set<int> to_del;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i: to_delete) to_del.insert(i);
        helper(root, true);
        return ans;
    }

    TreeNode* helper(TreeNode* root, bool is_root) {
        if(root == NULL) return NULL;
        bool del = to_del.find(root->val) != to_del.end();
        if(is_root && !del) ans.push_back(root);
        root->left = helper(root->left, del);
        root->right = helper(root->right, del);
        return del? NULL : root;
    }

};
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
    int ans = 0;
    map<TreeNode*, map<bool, int>> mp;
    int zigzag(TreeNode* root, bool dir) {
        if(!root) return -1;
        if(mp.count(root) && mp[root].count(dir)) return mp[root][dir];
        int ans = 0;
        if(dir)
            ans = 1 + zigzag(root->left, !dir);
        if(!dir)
            ans = 1 + zigzag(root->right, !dir);            
        return mp[root][dir] = ans;
    }
    
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        
        ans = max(ans, zigzag(root, 1));
        ans = max(ans, zigzag(root, 0));        
        
        if(root->left)
        longestZigZag(root->left);

        if(root->right)
        longestZigZag(root->right);

        return ans;
    }
};
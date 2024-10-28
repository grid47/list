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
    int maxLevelSum(TreeNode* root) {
        int ans = 1, mx= root->val;
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 1;
        while(!q.empty()) {
            int sz = q.size();
            int sum = 0;
            while(sz--) {
                TreeNode* n = q.front();
                q.pop();
                sum += n->val;
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);

            }
            if(sum > mx) {
                ans = lvl;
                mx = sum;
            }
            lvl++;
        }
        return ans;
    }
};
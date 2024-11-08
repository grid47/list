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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool isEI = true;
        // increasing - I
        // even - E
        while(!q.empty()) {
            int sz = q.size();
            int prv = isEI? INT_MIN : INT_MAX;
            while(sz--) {
                TreeNode* n = q.front();
                q.pop();
                if(isEI) {
                    if(n->val % 2 == 0) return false;
                    if(n->val <= prv)    return false;
                } else {
                    if(n->val % 2 == 1) return false;                    
                    if(n->val >= prv)    return false;
                }
                prv = n->val;
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            isEI = !isEI;
        }

        return true;
    }
};
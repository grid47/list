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
        
    int minimumOperations(TreeNode* root) {
        int cnt = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            vector<int> arr, idx(sz);
            while(sz--) {
                auto it = q.front();
                q.pop();
                arr.push_back(it->val);
                if(it->left != NULL) q.push(it->left);
                if(it->right!= NULL) q.push(it->right);
            }
            // cout << sz << " ";
            iota(idx.begin(), idx.end(), 0);
            sort(idx.begin(), idx.end(), [&](int i, int j) { return arr[i] < arr[j]; });
            for(int i = 0; i < idx.size(); i++)
                for(; idx[i] != i; cnt++)
                    swap(idx[i], idx[idx[i]]);
        }
        return cnt;
    }
};
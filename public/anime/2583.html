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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            long long sum = 0;
            while(sz--) {
                auto it = q.front();
                sum += it->val;
                q.pop();
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
            pq.push(sum);
            if(pq.size() > k) pq.pop();
        }
        if(pq.size() < k) return -1;
        return pq.top();
    }
};
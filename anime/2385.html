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
    unordered_map<int, vector<int>> mp;
public:
    int amountOfTime(TreeNode* root, int start) {
        graph(root);

        queue<int> q;
        q.push(start);
        unordered_map<int, bool> seen;
        seen[start] = true;
        int timer = 0;
        for(; q.size(); timer++) {
            int n = q.size();
            while(n--) {
                auto node = q.front();
                q.pop();
                for(int i: mp[node]) {
                    if(!seen[i]) {
                        seen[i] = true;
                        q.push(i);
                    }
                }
            }
        }
        
        return timer-1;
    }

    void graph(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, -1});
        while(!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();
            if(parent != -1) {
                mp[parent].push_back(node->val);
                mp[node->val].push_back(parent);
            }
            if(node->left) q.push({node->left, node->val});
            if(node->right) q.push({node->right, node->val});
        }
    }
};
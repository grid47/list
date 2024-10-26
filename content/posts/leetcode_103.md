
+++
authors = ["Yasir"]
title = "Leetcode 103: Binary Tree Zigzag Level Order Traversal"
date = "2024-07-16"
description = "Solution to Leetcode 103"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> tmp;
        queue<TreeNode*> q;

        if(root == NULL) return ans;
        q.push(root);

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                TreeNode* it = q.front();
                q.pop();
                tmp.push_back(it->val);
                if(it->left  != NULL) q.push(it->left);
                if(it->right != NULL) q.push(it->right);
            }
            ans.push_back(tmp);
            tmp.clear();
        }
        return ans;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans = levelOrder(root);
        for(int i = 1; i < ans.size(); i += 2)
        {
            vector<int> tmp = ans[i];
            reverse(tmp.begin(), tmp.end());
            ans[i] = tmp;
        }
        return ans;

    }
};
{{< /highlight >}}


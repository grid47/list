
+++
authors = ["Yasir"]
title = "Leetcode 199: Binary Tree Right Side View"
date = "2024-04-11"
description = "Solution to Leetcode 199"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/binary-tree-right-side-view/description/)

---

**Code:**

{{< highlight html >}}
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        list<TreeNode*> q;
        q.push_back(root);
        while(!q.empty()) {
            vector<int> res;
            int sz = q.size();
            while(sz--) {
                auto tmp = q.front();
                q.pop_front();
                res.push_back(tmp->val);
                if(tmp->left) q.push_back(tmp->left);
                if(tmp->right) q.push_back(tmp->right);
            }
            ans.push_back(res.back());
        }
        return ans;
    }
};
{{< /highlight >}}


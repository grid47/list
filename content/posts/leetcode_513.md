
+++
authors = ["Yasir"]
title = "Leetcode 513: Find Bottom Left Tree Value"
date = "2023-06-02"
description = "Solution to Leetcode 513"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-bottom-left-tree-value/description/)

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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = q.front()->val;
        while(!q.empty()) {
            int sz = q.size();
            res = q.front()->val;
            while(sz-- > 0) {
                root = q.front();
                q.pop();
                if(root->left)  q.push(root->left);
                if(root->right) q.push(root->right);                
            }
        }
        return res;
    }
};
{{< /highlight >}}


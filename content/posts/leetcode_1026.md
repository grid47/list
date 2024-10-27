
+++
authors = ["Yasir"]
title = "Leetcode 1026: Maximum Difference Between Node and Ancestor"
date = "2022-01-06"
description = "Solution to Leetcode 1026"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/)

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
    int maxAncestorDiff(TreeNode* root) {
        return helper(root, root->val, root->val);
    }
    int helper(TreeNode* node, int mx, int mn) {
        if(!node) return mx - mn;
        mx = max(mx, node->val);
        mn = min(mn, node->val);
        
        return max(helper(node->left, mx, mn), helper(node->right, mx, mn));
    }
};
{{< /highlight >}}


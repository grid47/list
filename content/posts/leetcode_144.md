
+++
authors = ["Yasir"]
title = "Leetcode 144: Binary Tree Preorder Traversal"
date = "2024-06-06"
description = "Solution to Leetcode 144"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/binary-tree-preorder-traversal/description/)

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
    void pre(TreeNode* root, vector<int> &ans) {
        if(!root) return;
        ans.push_back(root->val);
        pre(root->left, ans);
        pre(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        pre(root, ans);
        return ans;
    }
};
{{< /highlight >}}


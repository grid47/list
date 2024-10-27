
+++
authors = ["Yasir"]
title = "Leetcode 814: Binary Tree Pruning"
date = "2022-08-06"
description = "Solution to Leetcode 814"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/binary-tree-pruning/description/)

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
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL) return root;
        root->left = pruneTree(root->left);
        root->right= pruneTree(root->right);
        if(!root->left && !root->right && root->val == 0)
                return NULL;
        return root;
    }
};
{{< /highlight >}}


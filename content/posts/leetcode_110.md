
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 110: Balanced Binary Tree"
date = "2024-07-11"
description = "Solution to Leetcode 110"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/balanced-binary-tree/description/)

---

**Code:**

{{< highlight cpp >}}
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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int l = h(root->left);
        int r = h(root->right);
        return abs(l - r) <= 1 &&
            isBalanced(root->left) &&
            isBalanced(root->right);
    }
    int h(TreeNode* node) {
        if(node == NULL) return 0;
        int l = h(node->left);
        int r = h(node->right);
        return 1 + max(l, r);
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


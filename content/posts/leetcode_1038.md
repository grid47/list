
+++
authors = ["Yasir"]
title = "Leetcode 1038: Binary Search Tree to Greater Sum Tree"
date = "2021-12-26"
description = "Solution to Leetcode 1038"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/)

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
    int pre;
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(root->right) bstToGst(root->right);
        pre = root->val = pre + root->val;
        if(root->left) bstToGst(root->left);
        return root;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


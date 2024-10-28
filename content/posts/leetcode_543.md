
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 543: Diameter of Binary Tree"
date = "2023-05-05"
description = "Solution to Leetcode 543"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/diameter-of-binary-tree/description/)

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
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        dep(d, root);
        return d;
    }
    
    int dep(int &d, TreeNode* node) {
        if(node == NULL) return 0;
        int l = dep(d, node->left);
        int r = dep(d, node->right);
        d = max(d, l + r);
        return 1 + max(l, r);
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


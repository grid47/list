
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1339: Maximum Product of Splitted Binary Tree"
date = "2021-03-02"
description = "Solution to Leetcode 1339"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/)

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
    long long sum = 0, ans = INT_MIN;
public:
    int maxProduct(TreeNode* root) {
        sum = ino(root);
        ino(root);
        return (int) (ans % (int) (1e9 + 7));
    }
    long long ino(TreeNode* root, bool s = true) {
        if (root == NULL) return 0;
        long long sub = ino(root->left) 
                      + ino(root->right)
                      + root->val;
        ans = max(ans, sub * (sum - sub));
        return sub;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


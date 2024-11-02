
+++
authors = ["Crafted by Me"]
title = "Leetcode 1339: Maximum Product of Splitted Binary Tree"
date = "2020-03-03"
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


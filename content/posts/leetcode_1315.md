
+++
authors = ["Crafted by Me"]
title = "Leetcode 1315: Sum of Nodes with Even-Valued Grandparent"
date = "2021-03-28"
description = "In-depth solution and explanation for Leetcode 1315: Sum of Nodes with Even-Valued Grandparent in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/description/)

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
    int sumEvenGrandparent(TreeNode* root) {
        return helper(root, 1, 1);
    }

    int helper(TreeNode* node, int p, int gp) {
        if (!node) return 0;
        return helper(node->left, node->val, p) + helper(node->right, node->val, p) + (gp % 2 == 0 ? node->val: 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1315.md" >}}
---

| Next : [LeetCode #1316: Distinct Echo Substrings](https://grid47.xyz/posts/leetcode_1316) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


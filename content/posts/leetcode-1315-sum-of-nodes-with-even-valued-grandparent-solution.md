
+++
authors = ["grid47"]
title = "Leetcode 1315: Sum of Nodes with Even-Valued Grandparent"
date = "2024-06-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1315: Sum of Nodes with Even-Valued Grandparent in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
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

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1318: Minimum Flips to Make a OR b Equal to c](https://grid47.xyz/posts/leetcode-1318-minimum-flips-to-make-a-or-b-equal-to-c-solution/) |
| --- |

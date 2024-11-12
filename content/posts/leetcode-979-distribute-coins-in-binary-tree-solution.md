
+++
authors = ["grid47"]
title = "Leetcode 979: Distribute Coins in Binary Tree"
date = "2024-08-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 979: Distribute Coins in Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/distribute-coins-in-binary-tree/description/)

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
    int mv;
public:
    int distributeCoins(TreeNode* root) {
        mv = 0;
        move(root, mv);
        return mv;
    }

    int move(TreeNode* r, int & mv) {
        if(r == nullptr) return 0;
        int left = move(r->left, mv);
        int right = move(r->right, mv);
        mv += abs(left) + abs(right);
        return r->val + left + right - 1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/979.md" >}}
---
{{< youtube YfdfIOeV_RU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #981: Time Based Key-Value Store](https://grid47.xyz/posts/leetcode-981-time-based-key-value-store-solution/) |
| --- |

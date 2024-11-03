
+++
authors = ["Crafted by Me"]
title = "Leetcode 979: Distribute Coins in Binary Tree"
date = "2022-02-27"
description = "In-depth solution and explanation for Leetcode 979: Distribute Coins in Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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

| Next : [LeetCode #980: Unique Paths III](https://grid47.xyz/posts/leetcode_980) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


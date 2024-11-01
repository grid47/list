
+++
authors = ["Crafted by Me"]
title = "Leetcode 979: Distribute Coins in Binary Tree"
date = "2022-02-27"
description = "Solution to Leetcode 979"
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


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


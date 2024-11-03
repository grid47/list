
+++
authors = ["Crafted by Me"]
title = "Leetcode 1123: Lowest Common Ancestor of Deepest Leaves"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1123: Lowest Common Ancestor of Deepest Leaves in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/description/)

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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root).first;
    }

    pair<TreeNode*, int> helper(TreeNode* root) {
        if(root == NULL) return {NULL, 0};
        auto left = helper(root->left);
        auto right = helper(root->right);
        if(left.second > right.second)
        return {left.first, left.second + 1};
        else if(left.second < right.second)
        return {right.first, right.second + 1};
        return {root, left.second + 1};
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1123.md" >}}
---
{{< youtube yVw0Q8QknJg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1124: Longest Well-Performing Interval](https://grid47.xyz/posts/leetcode_1124) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


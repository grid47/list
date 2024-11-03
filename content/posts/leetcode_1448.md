
+++
authors = ["Crafted by Me"]
title = "Leetcode 1448: Count Good Nodes in Binary Tree"
date = "2020-11-15"
description = "In-depth solution and explanation for Leetcode 1448: Count Good Nodes in Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/)

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
    int goodNodes(TreeNode* root) {
        return good(root, -100000);
    }

    int good(TreeNode* node, int mx) {
        if(node == NULL) return 0;
        int res = (node->val >= mx) ? 1: 0;
        res += good(node->left, max(mx, node->val));
        res += good(node->right, max(mx, node->val));
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1448.md" >}}
---
{{< youtube 2AdOBLcj2wk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1449: Form Largest Integer With Digits That Add up to Target](https://grid47.xyz/posts/leetcode_1449) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}



+++
authors = ["Crafted by Me"]
title = "Leetcode 114: Flatten Binary Tree to Linked List"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 114: Flatten Binary Tree to Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Tree","Depth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    void flatten(TreeNode* root) {

        if( root == NULL) return;

        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = nullptr;

        TreeNode* node = root;
        while(node->right) node = node->right;

        node->right = tmp;
        flatten(root->right); 

    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/114.md" >}}
---
{{< youtube rKnD7rLT0lI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #115: Distinct Subsequences](https://grid47.xyz/posts/leetcode_115) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


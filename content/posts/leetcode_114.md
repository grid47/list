
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 114: Flatten Binary Tree to Linked List"
date = "2024-07-09"
description = "Solution to Leetcode 114"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/)

---
{{< youtube rKnD7rLT0lI >}}
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


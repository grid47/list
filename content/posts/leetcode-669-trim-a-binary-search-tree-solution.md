
+++
authors = ["grid47"]
title = "Leetcode 669: Trim a Binary Search Tree"
date = "2024-09-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 669: Trim a Binary Search Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/trim-a-binary-search-tree/description/)

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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL) return NULL;

       if(root->val < low) {
           return trimBST(root->right, low, high);
       } else if(root->val > high) {
            return trimBST(root->left, low, high);
       }

        root->left = trimBST(root->left, low, high);
        root->right= trimBST(root->right, low, high);
        return root;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/669.md" >}}
---
{{< youtube jwt5mTjEXGc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #670: Maximum Swap](https://grid47.xyz/posts/leetcode-670-maximum-swap-solution/) |
| --- |

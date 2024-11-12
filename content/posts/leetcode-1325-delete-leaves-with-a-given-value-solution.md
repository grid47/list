
+++
authors = ["grid47"]
title = "Leetcode 1325: Delete Leaves With a Given Value"
date = "2024-06-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1325: Delete Leaves With a Given Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/delete-leaves-with-a-given-value/description/)

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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root->left) root->left = removeLeafNodes(root->left, target);
        if(root->right) root->right = removeLeafNodes(root->right, target);
        return root->left == root->right && root->val == target ? nullptr : root;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1325.md" >}}
---
{{< youtube FqAoYAwbwV8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1328: Break a Palindrome](https://grid47.xyz/posts/leetcode-1328-break-a-palindrome-solution/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 814: Binary Tree Pruning"
date = "2024-08-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 814: Binary Tree Pruning in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/binary-tree-pruning/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/814.webp" 
    alt="A binary tree where branches are pruned, with the pruned branches glowing softly as they are removed."
    caption="Solution to LeetCode 814: Binary Tree Pruning Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL) return root;
        root->left = pruneTree(root->left);
        root->right= pruneTree(root->right);
        if(!root->left && !root->right && root->val == 0)
                return NULL;
        return root;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/814.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #816: Ambiguous Coordinates](https://grid47.xyz/posts/leetcode-816-ambiguous-coordinates-solution/) |
| --- |

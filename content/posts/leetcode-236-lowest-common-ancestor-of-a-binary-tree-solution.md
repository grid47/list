
+++
authors = ["grid47"]
title = "Leetcode 236: Lowest Common Ancestor of a Binary Tree"
date = "2024-10-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 236: Lowest Common Ancestor of a Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/236.webp" 
    alt="Similar to the previous idea, with paths gently intersecting to show the common ancestor in a non-search tree."
    caption="Solution to LeetCode 236: Lowest Common Ancestor of a Binary Tree Problem"
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        return !left? right: !right? left : root;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/236.md" >}}
---
{{< youtube gRHnWbKiUIE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #237: Delete Node in a Linked List](https://grid47.xyz/posts/leetcode-237-delete-node-in-a-linked-list-solution/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 235: Lowest Common Ancestor of a Binary Search Tree"
date = "2024-10-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 235: Lowest Common Ancestor of a Binary Search Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/235.webp" 
    alt="Two paths glowing brightly as they meet at the lowest common ancestor in a binary search tree."
    caption="Solution to LeetCode 235: Lowest Common Ancestor of a Binary Search Tree Problem"
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
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/235.md" >}}
---
{{< youtube ML6vGnziUaI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #236: Lowest Common Ancestor of a Binary Tree](https://grid47.xyz/posts/leetcode-236-lowest-common-ancestor-of-a-binary-tree-solution/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 543: Diameter of Binary Tree"
date = "2024-09-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 543: Diameter of Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/diameter-of-binary-tree/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/543.webp" 
    alt="A binary tree where the longest path between two nodes is highlighted, glowing softly to show the tree's diameter."
    caption="Solution to LeetCode 543: Diameter of Binary Tree Problem"
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
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        dep(d, root);
        return d;
    }
    
    int dep(int &d, TreeNode* node) {
        if(node == NULL) return 0;
        int l = dep(d, node->left);
        int r = dep(d, node->right);
        d = max(d, l + r);
        return 1 + max(l, r);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/543.md" >}}
---
{{< youtube 6lJZ_xj1mEo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #547: Number of Provinces](https://grid47.xyz/posts/leetcode-547-number-of-provinces-solution/) |
| --- |

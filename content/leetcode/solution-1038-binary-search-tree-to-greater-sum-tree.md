
+++
authors = ["grid47"]
title = "Leetcode 1038: Binary Search Tree to Greater Sum Tree"
date = "2024-07-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1038: Binary Search Tree to Greater Sum Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "FiGdEA4herM"
youtube_upload_date="2022-11-13"
youtube_thumbnail="https://i.ytimg.com/vi/FiGdEA4herM/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/)

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
    int pre;
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(root->right) bstToGst(root->right);
        pre = root->val = pre + root->val;
        if(root->left) bstToGst(root->left);
        return root;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1038.md" >}}
---
{{< youtube FiGdEA4herM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1039: Minimum Score Triangulation of Polygon](https://grid47.xyz/leetcode/solution-1039-minimum-score-triangulation-of-polygon/) |
| --- |
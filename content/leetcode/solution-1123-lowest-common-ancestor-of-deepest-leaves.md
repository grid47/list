
+++
authors = ["grid47"]
title = "Leetcode 1123: Lowest Common Ancestor of Deepest Leaves"
date = "2024-07-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1123: Lowest Common Ancestor of Deepest Leaves in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "yVw0Q8QknJg"
youtube_upload_date="2020-06-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/yVw0Q8QknJg/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/description/)

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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root).first;
    }

    pair<TreeNode*, int> helper(TreeNode* root) {
        if(root == NULL) return {NULL, 0};
        auto left = helper(root->left);
        auto right = helper(root->right);
        if(left.second > right.second)
        return {left.first, left.second + 1};
        else if(left.second < right.second)
        return {right.first, right.second + 1};
        return {root, left.second + 1};
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1123.md" >}}
---
{{< youtube yVw0Q8QknJg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1124: Longest Well-Performing Interval](https://grid47.xyz/leetcode/solution-1124-longest-well-performing-interval/) |
| --- |
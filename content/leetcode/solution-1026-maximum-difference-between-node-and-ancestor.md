
+++
authors = ["grid47"]
title = "Leetcode 1026: Maximum Difference Between Node and Ancestor"
date = "2024-07-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1026: Maximum Difference Between Node and Ancestor in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "f37BCBHGFGA"
youtube_upload_date="2020-07-07"
youtube_thumbnail="https://i.ytimg.com/vi/f37BCBHGFGA/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/)

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
    int maxAncestorDiff(TreeNode* root) {
        return helper(root, root->val, root->val);
    }
    int helper(TreeNode* node, int mx, int mn) {
        if(!node) return mx - mn;
        mx = max(mx, node->val);
        mn = min(mn, node->val);
        
        return max(helper(node->left, mx, mn), helper(node->right, mx, mn));
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1026.md" >}}
---
{{< youtube f37BCBHGFGA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1027: Longest Arithmetic Subsequence](https://grid47.xyz/leetcode/solution-1027-longest-arithmetic-subsequence/) |
| --- |
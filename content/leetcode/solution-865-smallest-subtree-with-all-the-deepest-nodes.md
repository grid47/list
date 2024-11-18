
+++
authors = ["grid47"]
title = "Leetcode 865: Smallest Subtree with all the Deepest Nodes"
date = "2024-08-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 865: Smallest Subtree with all the Deepest Nodes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "QF7ZBH8mXHE"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/)

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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return lcadn(root).first;
    }

    pair<TreeNode*, int> lcadn(TreeNode* root) {
        if(root == NULL) return {NULL, 0};
        auto lft = lcadn(root->left);
        auto rht = lcadn(root->right);
        if(lft.second < rht.second) {
            return {rht.first, rht.second + 1};
        } else if (lft.second > rht.second) {
            return {lft.first, lft.second + 1};            
        }
        return {root, lft.second + 1};
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/865.md" >}}
---
{{< youtube QF7ZBH8mXHE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #866: Prime Palindrome](https://grid47.xyz/leetcode/solution-866-prime-palindrome/) |
| --- |

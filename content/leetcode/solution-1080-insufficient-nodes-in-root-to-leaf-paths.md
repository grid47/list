
+++
authors = ["grid47"]
title = "Leetcode 1080: Insufficient Nodes in Root to Leaf Paths"
date = "2024-07-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1080: Insufficient Nodes in Root to Leaf Paths in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



[`Problem Link`](https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/description/)

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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(!root) return NULL;
        if(root->left == NULL && root->right == NULL)
            return root->val < limit ? NULL : root;
        root->left = sufficientSubset(root->left, limit - root->val);
        root->right= sufficientSubset(root->right, limit - root->val);
        return root->left == root->right ? NULL : root;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1080.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1081: Smallest Subsequence of Distinct Characters](https://grid47.xyz/leetcode/solution-1081-smallest-subsequence-of-distinct-characters/) |
| --- |
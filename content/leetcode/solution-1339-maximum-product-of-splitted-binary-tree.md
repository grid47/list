
+++
authors = ["grid47"]
title = "Leetcode 1339: Maximum Product of Splitted Binary Tree"
date = "2024-06-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1339: Maximum Product of Splitted Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/)

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
    long long sum = 0, ans = INT_MIN;
public:
    int maxProduct(TreeNode* root) {
        sum = ino(root);
        ino(root);
        return (int) (ans % (int) (1e9 + 7));
    }
    long long ino(TreeNode* root, bool s = true) {
        if (root == NULL) return 0;
        long long sub = ino(root->left) 
                      + ino(root->right)
                      + root->val;
        ans = max(ans, sub * (sum - sub));
        return sub;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1339.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1343: Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold](https://grid47.xyz/leetcode/solution-1343-number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/) |
| --- |

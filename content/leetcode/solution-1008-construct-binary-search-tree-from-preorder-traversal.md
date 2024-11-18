
+++
authors = ["grid47"]
title = "Leetcode 1008: Construct Binary Search Tree from Preorder Traversal"
date = "2024-07-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1008: Construct Binary Search Tree from Preorder Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Tree","Binary Search Tree","Monotonic Stack","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/)

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
    int i = 0;
public:
    TreeNode* bstFromPreorder(vector<int>& pre, int bound = INT_MAX) {
        if(i == pre.size() || pre[i] > bound) return NULL;
        
        TreeNode* root = new TreeNode(pre[i++]);
        root->left = bstFromPreorder(pre, root->val);
        root->right = bstFromPreorder(pre, bound);
        return root;
    }
    
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1008.md" >}}
---
{{< youtube 30WqiTVp8Kc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1010: Pairs of Songs With Total Durations Divisible by 60](https://grid47.xyz/leetcode/solution-1010-pairs-of-songs-with-total-durations-divisible-by-60/) |
| --- |

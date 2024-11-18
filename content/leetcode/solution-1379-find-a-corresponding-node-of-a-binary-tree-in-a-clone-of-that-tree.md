
+++
authors = ["grid47"]
title = "Leetcode 1379: Find a Corresponding Node of a Binary Tree in a Clone of That Tree"
date = "2024-06-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1379: Find a Corresponding Node of a Binary Tree in a Clone of That Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/description/)

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
    TreeNode* ans;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        if (cloned == NULL)
            return cloned;
        if (cloned->val == target->val) // If target node found in cloned tree save it into a variable.
            ans = cloned;
        getTargetCopy(original, cloned->left, target);
        getTargetCopy(original, cloned->right, target);
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1379.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1380: Lucky Numbers in a Matrix](https://grid47.xyz/leetcode/solution-1380-lucky-numbers-in-a-matrix/) |
| --- |

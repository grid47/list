
+++
authors = ["Yasir"]
title = "Leetcode 1379: Find a Corresponding Node of a Binary Tree in a Clone of That Tree"
date = "2021-01-19"
description = "Solution to Leetcode 1379"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/description/)

---

**Code:**

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


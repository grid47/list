
+++
authors = ["Yasir"]
title = "Leetcode 99: Recover Binary Search Tree"
date = "2024-07-18"
description = "Solution to Leetcode 99"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/recover-binary-search-tree/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
    TreeNode *prv = NULL, * fst = NULL , *scd = NULL;
    void inorder(TreeNode* node)
    {
        if(!node) return;
        inorder(node->left);
        if (prv && node->val < prv->val) {
            if (!fst)  fst = prv;
            scd = node; 
        }
        prv = node;
        inorder(node->right);
    }
public:
    void recoverTree(TreeNode* node) {
        inorder(node);
        swap(fst->val, scd->val);
    }
};
{{< /highlight >}}


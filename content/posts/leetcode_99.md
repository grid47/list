
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 99: Recover Binary Search Tree"
date = "2024-07-24"
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
{{< youtube bJBwOMPhe6Y >}}
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/99.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


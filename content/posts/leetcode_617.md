
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 617: Merge Two Binary Trees"
date = "2023-02-21"
description = "Solution to Leetcode 617"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/merge-two-binary-trees/description/)

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
    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
        TreeNode* ans = new TreeNode(0);
        if(r1 == NULL && r2 == NULL) return NULL;
        if(r1 != NULL && r2 != NULL)
            ans->val = r1->val + r2->val;
        else if(r1 == NULL)
            ans->val = r2->val;
        else
            ans->val = r1->val;
        ans->left = mergeTrees(r1?r1->left:NULL, r2?r2->left:NULL);
        ans->right = mergeTrees(r1?r1->right:NULL, r2?r2->right:NULL);
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/617.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


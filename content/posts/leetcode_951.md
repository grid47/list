
+++
authors = ["Yasir"]
title = "Leetcode 951: Flip Equivalent Binary Trees"
date = "2022-03-21"
description = "Solution to Leetcode 951"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/flip-equivalent-binary-trees/description/)

---

**Code:**

{{< highlight html >}}
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL || root2 == NULL) 
            return root1 == root2;

        return (root1->val == root2->val) && 
(flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right) ||
flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));

    }
};
{{< /highlight >}}


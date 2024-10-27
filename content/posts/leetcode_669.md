
+++
authors = ["Yasir"]
title = "Leetcode 669: Trim a Binary Search Tree"
date = "2022-12-29"
description = "Solution to Leetcode 669"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/trim-a-binary-search-tree/description/)

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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL) return NULL;

       if(root->val < low) {
           return trimBST(root->right, low, high);
       } else if(root->val > high) {
            return trimBST(root->left, low, high);
       }

        root->left = trimBST(root->left, low, high);
        root->right= trimBST(root->right, low, high);
        return root;
    }
};
{{< /highlight >}}


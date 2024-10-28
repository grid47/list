
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 623: Add One Row to Tree"
date = "2023-02-14"
description = "Solution to Leetcode 623"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/add-one-row-to-tree/description/)

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
    TreeNode* addOneRow(TreeNode* root, int val, int d) {
        if (d == 1) {
            TreeNode* newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }
        if (d == 0) {
            TreeNode* newroot = new TreeNode(val);
            newroot->right = root;
            return newroot;
        }

        if(!root) return nullptr;
        else if(d == 2) {
            root->left  = addOneRow(root->left, val, 1);
            root->right = addOneRow(root->right, val, 0);            
            return root;
        } else if(d > 2) {
            root->left  = addOneRow(root->left, val, d - 1);
            root->right = addOneRow(root->right, val,d - 1);            
        }
        return root;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


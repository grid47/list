
+++
authors = ["Yasir"]
title = "Leetcode 111: Minimum Depth of Binary Tree"
date = "2024-07-09"
description = "Solution to Leetcode 111"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-depth-of-binary-tree/description/)

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
    int minDepth(TreeNode* root) {
        
        if(root == NULL) return 0;
        
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        
        if(root->left && root->right) {
            return 1 + ((l < r)? l: r);            
        }
        
        if(root->left) {
            return 1 + l;                        
        }

        return 1 + r;                        
    }
};
{{< /highlight >}}


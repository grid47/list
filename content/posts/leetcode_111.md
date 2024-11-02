
+++
authors = ["Crafted by Me"]
title = "Leetcode 111: Minimum Depth of Binary Tree"
date = "2023-07-14"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/111.md" >}}
---
{{< youtube Ukbbnzxmd8o >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


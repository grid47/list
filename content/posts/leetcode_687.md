
+++
authors = ["Crafted by Me"]
title = "Leetcode 687: Longest Univalue Path"
date = "2022-12-16"
description = "In-depth solution and explanation for Leetcode 687: Longest Univalue Path in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-univalue-path/description/)

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
    int maxi;
public:
    int longestUnivaluePath(TreeNode* root) {
        maxi = 0;
        if((root == NULL) || (root->left == NULL && root->right == NULL)  )
        return 0;
        dfs(root);
        return maxi;
    }

    int dfs(TreeNode *root) {
        if(root == NULL) return 0;
        int l = 0, r = 0;
        int lft = dfs(root->left);
        int rgt = dfs(root->right);
        if((root->left != NULL) && (root->left->val == root->val))
        l = lft;
        if((root->right != NULL) && (root->right->val == root->val))
        r = rgt;        

        maxi = max(maxi, l + r);
        return 1 + max(l, r);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/687.md" >}}
---


"| 688: Knight Probability in Chessboard |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


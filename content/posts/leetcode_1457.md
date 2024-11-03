
+++
authors = ["Crafted by Me"]
title = "Leetcode 1457: Pseudo-Palindromic Paths in a Binary Tree"
date = "2020-11-06"
description = "In-depth solution and explanation for Leetcode 1457: Pseudo-Palindromic Paths in a Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/)

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
    int pseudoPalindromicPaths (TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int cnt){
        if(!root) return 0;
        cnt ^= (1 << (root->val - 1));
        int res = dfs(root->left, cnt) + dfs(root->right, cnt);
        if(root->left == NULL && root->right == NULL && (cnt &(cnt -1)) == 0)
            res++;
        return res;
    }

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1457.md" >}}
---

| Next : [LeetCode #1458: Max Dot Product of Two Subsequences](https://grid47.xyz/posts/leetcode_1458) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


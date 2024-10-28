
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1457: Pseudo-Palindromic Paths in a Binary Tree"
date = "2020-11-02"
description = "Solution to Leetcode 1457"
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


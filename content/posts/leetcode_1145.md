
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1145: Binary Tree Coloring Game"
date = "2021-09-11"
description = "Solution to Leetcode 1145"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/binary-tree-coloring-game/description/)

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
    int lft, rht, val;
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        val = x;
        cout<< n;
        n = count(root);
        cout<< n << "\n";        
        return max(max(lft, rht), n - lft-rht -1) > n/2;
    }

    int count(TreeNode* root) {
        if(!root) return 0;
        int l = count(root->left);
        int r = count(root->right);
        if(root->val == val)
        lft = l, rht = r;
        return l + r + 1;
    }

};



{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1008: Construct Binary Search Tree from Preorder Traversal"
date = "2022-01-26"
description = "Solution to Leetcode 1008"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/)

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
    int i = 0;
public:
    TreeNode* bstFromPreorder(vector<int>& pre, int bound = INT_MAX) {
        if(i == pre.size() || pre[i] > bound) return NULL;
        
        TreeNode* root = new TreeNode(pre[i++]);
        root->left = bstFromPreorder(pre, root->val);
        root->right = bstFromPreorder(pre, bound);
        return root;
    }
    
    
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

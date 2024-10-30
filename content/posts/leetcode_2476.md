
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2476: Closest Nodes Queries in a Binary Search Tree"
date = "2018-01-20"
description = "Solution to Leetcode 2476"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/description/)

---
{{< youtube nan >}}
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
    vector<int> v;
    void traverse(TreeNode* root) {
        if(root != nullptr) {
            traverse(root->left);
            if(v.empty() || v.back() < root->val)
                v.push_back(root->val);
            traverse(root->right);
        }
    }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        traverse(root);
        vector<vector<int>> res;
        for(int q: queries) {
            auto it = lower_bound(begin(v), end(v), q);
            if(it != end(v) && *it==q)
            res.push_back({q, q});
            else
            res.push_back({it == begin(v)? -1: *prev(it), it == end(v)? -1: *it});
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


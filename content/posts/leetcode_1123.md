
+++
authors = ["Yasir"]
title = "Leetcode 1123: Lowest Common Ancestor of Deepest Leaves"
date = "2021-10-02"
description = "Solution to Leetcode 1123"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/description/)

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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root).first;
    }

    pair<TreeNode*, int> helper(TreeNode* root) {
        if(root == NULL) return {NULL, 0};
        auto left = helper(root->left);
        auto right = helper(root->right);
        if(left.second > right.second)
        return {left.first, left.second + 1};
        else if(left.second < right.second)
        return {right.first, right.second + 1};
        return {root, left.second + 1};
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


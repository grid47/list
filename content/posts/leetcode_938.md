
+++
authors = ["Yasir"]
title = "Leetcode 938: Range Sum of BST"
date = "2022-04-03"
description = "Solution to Leetcode 938"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/range-sum-of-bst/description/)

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

    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        int sum = 0;
        sum += rangeSumBST(root->left, low, high);
        if(root->val >= low && root->val <= high)
            sum += root->val;
        sum += rangeSumBST(root->right, low, high);
        return sum;
    }
};
{{< /highlight >}}



+++
authors = ["Yasir"]
title = "Leetcode 230: Kth Smallest Element in a BST"
date = "2024-03-12"
description = "Solution to Leetcode 230"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/)

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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        // stk.push(root);
        TreeNode* node= root;
        while(!stk.empty() || node) {
            if(node) {
                stk.push(node);
                node = node->left;
            } else {
                node = stk.top();
                stk.pop();
                k--;
                if(k == 0) return node->val;
                node = node->right;
            }
        }
        return NULL;
    }
};
{{< /highlight >}}


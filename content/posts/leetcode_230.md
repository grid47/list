
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 230: Kth Smallest Element in a BST"
date = "2024-03-13"
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


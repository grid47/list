
+++
authors = ["Crafted by Me"]
title = "Leetcode 1448: Count Good Nodes in Binary Tree"
date = "2020-11-14"
description = "Solution to Leetcode 1448"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/)

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
    int goodNodes(TreeNode* root) {
        return good(root, -100000);
    }

    int good(TreeNode* node, int mx) {
        if(node == NULL) return 0;
        int res = (node->val >= mx) ? 1: 0;
        res += good(node->left, max(mx, node->val));
        res += good(node->right, max(mx, node->val));
        return res;
    }
};
{{< /highlight >}}


---
{{< youtube 2AdOBLcj2wk >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


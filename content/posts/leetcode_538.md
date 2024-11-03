
+++
authors = ["Crafted by Me"]
title = "Leetcode 538: Convert BST to Greater Tree"
date = "2023-05-14"
description = "In-depth solution and explanation for Leetcode 538: Convert BST to Greater Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/convert-bst-to-greater-tree/description/)

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

    int sum = 0;

public:

    TreeNode* convertBST(TreeNode* root) {
        convert(root);
        return root;
    }

    void convert(TreeNode* root) {
        if(!root) return;
        convert(root->right);
        root->val += sum;
        sum = root->val;
        convert(root->left);
    }

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/538.md" >}}
---
{{< youtube AFDxiYO9XzY >}}
| Next : [LeetCode #539: Minimum Time Difference](https://grid47.xyz/posts/leetcode_539) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


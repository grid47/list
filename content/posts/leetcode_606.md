
+++
authors = ["Crafted by Me"]
title = "Leetcode 606: Construct String from Binary Tree"
date = "2023-03-06"
description = "Solution to Leetcode 606"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/construct-string-from-binary-tree/description/)

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
    string tree2str(TreeNode* root) {
        if(root == NULL) return "";
        string left  = tree2str(root->left);
        if(left!= "") left = '(' + left + ')';
        string right = tree2str(root->right);
        if(right != "") right = '(' + right + ')';
        if(left == "" && right != "") left = "()";
        // if(left != "" && right == "") right = "()";        
        return to_string(root->val)+left+right;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/606.md" >}}
---
{{< youtube b1WpYxnuebQ >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


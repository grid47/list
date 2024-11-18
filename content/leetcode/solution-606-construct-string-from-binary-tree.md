
+++
authors = ["grid47"]
title = "Leetcode 606: Construct String from Binary Tree"
date = "2024-09-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 606: Construct String from Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/construct-string-from-binary-tree/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/606.webp" 
    alt="A binary tree where a string is being constructed by traversing the tree, with each character softly glowing."
    caption="Solution to LeetCode 606: Construct String from Binary Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #609: Find Duplicate File in System](https://grid47.xyz/leetcode/solution-609-find-duplicate-file-in-system/) |
| --- |

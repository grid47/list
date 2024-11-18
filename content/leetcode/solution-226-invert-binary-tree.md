
+++
authors = ["grid47"]
title = "Leetcode 226: Invert Binary Tree"
date = "2024-10-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 226: Invert Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "JUyhWTDT2YI"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/226.webp"
+++



[`Problem Link`](https://leetcode.com/problems/invert-binary-tree/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/226.webp" 
    alt="A tree slowly flipping upside down, with nodes glowing as they invert."
    caption="Solution to LeetCode 226: Invert Binary Tree Problem"
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/226.md" >}}
---
{{< youtube JUyhWTDT2YI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #228: Summary Ranges](https://grid47.xyz/leetcode/solution-228-summary-ranges/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 538: Convert BST to Greater Tree"
date = "2024-09-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 538: Convert BST to Greater Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "AFDxiYO9XzY"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/538.webp"
+++



[`Problem Link`](https://leetcode.com/problems/convert-bst-to-greater-tree/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/538.webp" 
    alt="A binary search tree where each node is gradually updated to a greater tree, with each transformation softly highlighted."
    caption="Solution to LeetCode 538: Convert BST to Greater Tree Problem"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #539: Minimum Time Difference](https://grid47.xyz/leetcode/solution-539-minimum-time-difference/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 669: Trim a Binary Search Tree"
date = "2024-09-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 669: Trim a Binary Search Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/669.webp"
youtube = "jwt5mTjEXGc"
youtube_upload_date="2021-10-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/jwt5mTjEXGc/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/trim-a-binary-search-tree/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/669.webp" 
    alt="A binary search tree where the tree is trimmed to fit a given range, with each trimmed node softly glowing."
    caption="Solution to LeetCode 669: Trim a Binary Search Tree Problem"
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL) return NULL;

       if(root->val < low) {
           return trimBST(root->right, low, high);
       } else if(root->val > high) {
            return trimBST(root->left, low, high);
       }

        root->left = trimBST(root->left, low, high);
        root->right= trimBST(root->right, low, high);
        return root;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/669.md" >}}
---
{{< youtube jwt5mTjEXGc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #670: Maximum Swap](https://grid47.xyz/leetcode/solution-670-maximum-swap/) |
| --- |

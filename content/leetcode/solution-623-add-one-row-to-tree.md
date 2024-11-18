
+++
authors = ["grid47"]
title = "Leetcode 623: Add One Row to Tree"
date = "2024-09-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 623: Add One Row to Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/623.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



[`Problem Link`](https://leetcode.com/problems/add-one-row-to-tree/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/623.webp" 
    alt="A binary tree where a new row is being added, with the new row glowing as it is inserted."
    caption="Solution to LeetCode 623: Add One Row to Tree Problem"
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
    TreeNode* addOneRow(TreeNode* root, int val, int d) {
        if (d == 1) {
            TreeNode* newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }
        if (d == 0) {
            TreeNode* newroot = new TreeNode(val);
            newroot->right = root;
            return newroot;
        }

        if(!root) return nullptr;
        else if(d == 2) {
            root->left  = addOneRow(root->left, val, 1);
            root->right = addOneRow(root->right, val, 0);            
            return root;
        } else if(d > 2) {
            root->left  = addOneRow(root->left, val, d - 1);
            root->right = addOneRow(root->right, val,d - 1);            
        }
        return root;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/623.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #624: Maximum Distance in Arrays](https://grid47.xyz/leetcode/solution-624-maximum-distance-in-arrays/) |
| --- |

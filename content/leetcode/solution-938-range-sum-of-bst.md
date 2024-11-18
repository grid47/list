
+++
authors = ["grid47"]
title = "Leetcode 938: Range Sum of BST"
date = "2024-08-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 938: Range Sum of BST in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "ISUXXRnKmx0"
youtube_upload_date="2020-04-30"
youtube_thumbnail="https://i.ytimg.com/vi/ISUXXRnKmx0/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/range-sum-of-bst/description/)

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

    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        int sum = 0;
        sum += rangeSumBST(root->left, low, high);
        if(root->val >= low && root->val <= high)
            sum += root->val;
        sum += rangeSumBST(root->right, low, high);
        return sum;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/938.md" >}}
---
{{< youtube ISUXXRnKmx0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #939: Minimum Area Rectangle](https://grid47.xyz/leetcode/solution-939-minimum-area-rectangle/) |
| --- |

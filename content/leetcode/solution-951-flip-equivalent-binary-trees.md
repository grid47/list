
+++
authors = ["grid47"]
title = "Leetcode 951: Flip Equivalent Binary Trees"
date = "2024-08-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 951: Flip Equivalent Binary Trees in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "izRDc1il9Pk"
youtube_upload_date="2021-08-14"
youtube_thumbnail="https://i.ytimg.com/vi/izRDc1il9Pk/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/flip-equivalent-binary-trees/description/)

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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL || root2 == NULL) 
            return root1 == root2;

        return (root1->val == root2->val) && 
(flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right) ||
flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));

    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/951.md" >}}
---
{{< youtube izRDc1il9Pk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #954: Array of Doubled Pairs](https://grid47.xyz/leetcode/solution-954-array-of-doubled-pairs/) |
| --- |

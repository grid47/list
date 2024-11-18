
+++
authors = ["grid47"]
title = "Leetcode 687: Longest Univalue Path"
date = "2024-08-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 687: Longest Univalue Path in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "ZeBr9JMcjrU"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/687.webp"
+++



[`Problem Link`](https://leetcode.com/problems/longest-univalue-path/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/687.webp" 
    alt="A tree where the longest univalue path is traced and softly glowing as it’s found."
    caption="Solution to LeetCode 687: Longest Univalue Path Problem"
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
    int maxi;
public:
    int longestUnivaluePath(TreeNode* root) {
        maxi = 0;
        if((root == NULL) || (root->left == NULL && root->right == NULL)  )
        return 0;
        dfs(root);
        return maxi;
    }

    int dfs(TreeNode *root) {
        if(root == NULL) return 0;
        int l = 0, r = 0;
        int lft = dfs(root->left);
        int rgt = dfs(root->right);
        if((root->left != NULL) && (root->left->val == root->val))
        l = lft;
        if((root->right != NULL) && (root->right->val == root->val))
        r = rgt;        

        maxi = max(maxi, l + r);
        return 1 + max(l, r);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/687.md" >}}
---
{{< youtube ZeBr9JMcjrU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #688: Knight Probability in Chessboard](https://grid47.xyz/leetcode/solution-688-knight-probability-in-chessboard/) |
| --- |

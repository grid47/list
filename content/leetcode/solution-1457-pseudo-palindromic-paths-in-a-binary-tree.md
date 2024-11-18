
+++
authors = ["grid47"]
title = "Leetcode 1457: Pseudo-Palindromic Paths in a Binary Tree"
date = "2024-06-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1457: Pseudo-Palindromic Paths in a Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Bit Manipulation","Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "MBsSpQnaFzg"
youtube_upload_date="2024-01-24"
youtube_thumbnail="https://i.ytimg.com/vi/MBsSpQnaFzg/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/)

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
    int pseudoPalindromicPaths (TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int cnt){
        if(!root) return 0;
        cnt ^= (1 << (root->val - 1));
        int res = dfs(root->left, cnt) + dfs(root->right, cnt);
        if(root->left == NULL && root->right == NULL && (cnt &(cnt -1)) == 0)
            res++;
        return res;
    }

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1457.md" >}}
---
{{< youtube MBsSpQnaFzg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1461: Check If a String Contains All Binary Codes of Size K](https://grid47.xyz/leetcode/solution-1461-check-if-a-string-contains-all-binary-codes-of-size-k/) |
| --- |

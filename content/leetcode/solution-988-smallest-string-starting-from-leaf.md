
+++
authors = ["grid47"]
title = "Leetcode 988: Smallest String Starting From Leaf"
date = "2024-07-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 988: Smallest String Starting From Leaf in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Backtracking","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "UvdWfxQ_ZDs"
youtube_upload_date="2024-04-17"
youtube_thumbnail="https://i.ytimg.com/vi/UvdWfxQ_ZDs/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/smallest-string-starting-from-leaf/description/)

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
    string ans = "~";
    string smallestFromLeaf(TreeNode* root) {
        recur(root, "");
        return ans;
    }
    void recur(TreeNode* node, string s) {
        if(!node) return;
        if(!node->left && !node->right) {
            ans = min(ans, char(node->val + 'a') + s);
        }
        cout << node->val<<'\n';
        recur(node->left,  char(node->val + 'a') + s);
        recur(node->right, char(node->val + 'a') + s);  
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/988.md" >}}
---
{{< youtube UvdWfxQ_ZDs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #990: Satisfiability of Equality Equations](https://grid47.xyz/leetcode/solution-990-satisfiability-of-equality-equations/) |
| --- |
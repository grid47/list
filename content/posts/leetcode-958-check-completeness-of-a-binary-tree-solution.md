
+++
authors = ["grid47"]
title = "Leetcode 958: Check Completeness of a Binary Tree"
date = "2024-08-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 958: Check Completeness of a Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/)

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
    bool isCompleteTree(TreeNode* root) {
        vector<TreeNode*> q;
        q.push_back(root);
        int i = 0;
        while(i < q.size() && q[i]) {
            q.push_back(q[i]->left);
            q.push_back(q[i]->right);
            i++;
        }
        while(i < q.size() && !q[i])
            i++;
        return i == q.size();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/958.md" >}}
---
{{< youtube 9Jhtrwxp9ME >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #959: Regions Cut By Slashes](https://grid47.xyz/posts/leetcode-959-regions-cut-by-slashes-solution/) |
| --- |

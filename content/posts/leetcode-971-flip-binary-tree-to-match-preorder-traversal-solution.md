
+++
authors = ["grid47"]
title = "Leetcode 971: Flip Binary Tree To Match Preorder Traversal"
date = "2024-08-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 971: Flip Binary Tree To Match Preorder Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/description/)

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
    vector<int> res;
    int i = 0;
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> fail = {-1};
        return dfs(root, voyage)? res: fail;
    }

    bool dfs(TreeNode* node, vector<int> &voyage) {
        if(node == NULL) return true;
        if(node->val != voyage[i++]) return false;
        if(node->left != NULL && node->left->val != voyage[i]) {
            res.push_back(node->val);
            return  dfs(node->right, voyage) && dfs(node->left, voyage);
        }
        return  dfs(node->left, voyage) && dfs(node->right, voyage);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/971.md" >}}
---
{{< youtube 6L25Q-42OXA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #973: K Closest Points to Origin](https://grid47.xyz/posts/leetcode-973-k-closest-points-to-origin-solution/) |
| --- |

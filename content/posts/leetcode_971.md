
+++
authors = ["Crafted by Me"]
title = "Leetcode 971: Flip Binary Tree To Match Preorder Traversal"
date = "2021-03-06"
description = "Solution to Leetcode 971"
tags = [
    
]
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


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


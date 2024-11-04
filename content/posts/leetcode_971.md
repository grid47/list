
+++
authors = ["Crafted by Me"]
title = "Leetcode 971: Flip Binary Tree To Match Preorder Traversal"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 971: Flip Binary Tree To Match Preorder Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #972: Equal Rational Numbers](https://grid47.xyz/posts/leetcode_972) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


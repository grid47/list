
+++
authors = ["Crafted by Me"]
title = "Leetcode 865: Smallest Subtree with all the Deepest Nodes"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 865: Smallest Subtree with all the Deepest Nodes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/)

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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return lcadn(root).first;
    }

    pair<TreeNode*, int> lcadn(TreeNode* root) {
        if(root == NULL) return {NULL, 0};
        auto lft = lcadn(root->left);
        auto rht = lcadn(root->right);
        if(lft.second < rht.second) {
            return {rht.first, rht.second + 1};
        } else if (lft.second > rht.second) {
            return {lft.first, lft.second + 1};            
        }
        return {root, lft.second + 1};
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/865.md" >}}
---
{{< youtube QF7ZBH8mXHE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #866: Prime Palindrome](https://grid47.xyz/posts/leetcode_866) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


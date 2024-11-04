
+++
authors = ["Crafted by Me"]
title = "Leetcode 1382: Balance a Binary Search Tree"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1382: Balance a Binary Search Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/balance-a-binary-search-tree/description/)

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
    vector<int> arr;
public:
    TreeNode* balanceBST(TreeNode* root) {
        inorder (root);
        return reform(0, arr.size()-1);
    }
    
    void inorder (TreeNode* root) {
        if(root == NULL ) return;
        inorder (root->left);
        arr.push_back(root->val);
        inorder (root->right);
    }
    
 TreeNode* reform(int l, int r) {
        if (l > r) return NULL;
     int mid = (l + r)/2;
     TreeNode* node = new TreeNode(arr[mid]);
     node->left = reform (l, mid -1);
     node->right= reform (mid +1, r);
     return node;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1382.md" >}}
---
{{< youtube 0KGdtzgL9Ec >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1383: Maximum Performance of a Team](https://grid47.xyz/posts/leetcode_1383) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


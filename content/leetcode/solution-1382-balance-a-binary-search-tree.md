
+++
authors = ["grid47"]
title = "Leetcode 1382: Balance a Binary Search Tree"
date = "2024-06-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1382: Balance a Binary Search Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Divide and Conquer","Greedy","Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1386: Cinema Seat Allocation](https://grid47.xyz/leetcode/solution-1386-cinema-seat-allocation/) |
| --- |

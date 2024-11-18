
+++
authors = ["grid47"]
title = "Leetcode 1145: Binary Tree Coloring Game"
date = "2024-07-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1145: Binary Tree Coloring Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/binary-tree-coloring-game/description/)

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
    int lft, rht, val;
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        val = x;
        cout<< n;
        n = count(root);
        cout<< n << "\n";        
        return max(max(lft, rht), n - lft-rht -1) > n/2;
    }

    int count(TreeNode* root) {
        if(!root) return 0;
        int l = count(root->left);
        int r = count(root->right);
        if(root->val == val)
        lft = l, rht = r;
        return l + r + 1;
    }

};



{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1145.md" >}}
---
{{< youtube DIXDTh-aOQ4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1146: Snapshot Array](https://grid47.xyz/leetcode/solution-1146-snapshot-array/) |
| --- |

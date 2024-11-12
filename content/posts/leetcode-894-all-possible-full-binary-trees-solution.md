
+++
authors = ["grid47"]
title = "Leetcode 894: All Possible Full Binary Trees"
date = "2024-08-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 894: All Possible Full Binary Trees in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Tree","Recursion","Memoization","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/all-possible-full-binary-trees/description/)

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
    vector<TreeNode*> allPossibleFBT(int n) {
        
        vector<vector<TreeNode*>> dp(n + 1);
        dp[1].push_back(new TreeNode(0));

        for(int i = 3; i <= n; i += 2) {
            for(int l = 1; l < i; l += 2) {
                // cout << l;
                for(auto it: dp[l])
                for(auto it2: dp[i - l - 1]) {
                    TreeNode* node = new TreeNode(0);
                    node->left = it;
                    node->right = it2;
                    dp[i].push_back(node);
                }
            }
        }
        return dp[n];        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/894.md" >}}
---
{{< youtube nZtrZPTTCAo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #896: Monotonic Array](https://grid47.xyz/posts/leetcode-896-monotonic-array-solution/) |
| --- |

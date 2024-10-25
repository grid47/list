
+++
authors = ["Yasir"]
title = "Leetcode 894: All Possible Full Binary Trees"
date = "2022-05-17"
description = "Solution to Leetcode 894"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/all-possible-full-binary-trees/description/)

---

**Code:**

{{< highlight html >}}
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


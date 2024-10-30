
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 894: All Possible Full Binary Trees"
date = "2022-05-21"
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}



+++
authors = ["Crafted by Me"]
title = "Leetcode 1530: Number of Good Leaf Nodes Pairs"
date = "2020-08-25"
description = "In-depth solution and explanation for Leetcode 1530: Number of Good Leaf Nodes Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/)

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
    int ans = 0;
    int countPairs(TreeNode* root, int dist) {
        dfs(root, dist);
        return ans;
    }
    
    vector<int> dfs(TreeNode* root, int dist) {
        if(!root) {
            vector<int> res(dist + 1, 0);
            return res;
        }
        
        if(root->left == NULL && root->right == NULL) {
            vector<int> res(dist + 1, 0);
            res[1]++;
            return res;
        }
        vector<int> left = dfs(root->left, dist);
        vector<int> right = dfs(root->right, dist);
        for(int i = 1; i <= dist - 1; i++) {
            for(int j = dist - 1; j >= 1; j--) {
                if(i + j <= dist)
                ans += left[i] * right[j];
            }
        }
        vector<int> res(dist + 1, 0);
        for(int i = 1; i <= dist - 2; i++ ) {
            res[i + 1] = left[i] + right[i];
        }
        return res;
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1530.md" >}}
---
{{< youtube f_epkBeS1LQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1531: String Compression II](https://grid47.xyz/posts/leetcode_1531) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


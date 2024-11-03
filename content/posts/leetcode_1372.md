
+++
authors = ["Crafted by Me"]
title = "Leetcode 1372: Longest ZigZag Path in a Binary Tree"
date = "2021-01-30"
description = "In-depth solution and explanation for Leetcode 1372: Longest ZigZag Path in a Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/)

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
    map<TreeNode*, map<bool, int>> mp;
    int zigzag(TreeNode* root, bool dir) {
        if(!root) return -1;
        if(mp.count(root) && mp[root].count(dir)) return mp[root][dir];
        int ans = 0;
        if(dir)
            ans = 1 + zigzag(root->left, !dir);
        if(!dir)
            ans = 1 + zigzag(root->right, !dir);            
        return mp[root][dir] = ans;
    }
    
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        
        ans = max(ans, zigzag(root, 1));
        ans = max(ans, zigzag(root, 0));        
        
        if(root->left)
        longestZigZag(root->left);

        if(root->right)
        longestZigZag(root->right);

        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1372.md" >}}
---
{{< youtube hbzdyIlvBKI >}}
| Next : [LeetCode #1373: Maximum Sum BST in Binary Tree](https://grid47.xyz/posts/leetcode_1373) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


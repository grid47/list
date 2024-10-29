
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 654: Maximum Binary Tree"
date = "2023-01-15"
description = "Solution to Leetcode 654"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-binary-tree/description/)

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        vector<TreeNode*> stk;
        
        for(int num : nums) {
            
            TreeNode* cur = new TreeNode(num);
            
            while(!stk.empty() && stk.back()->val < num) {
                cur->left = stk.back();
                stk.pop_back();
            }
            
            if(!stk.empty()) stk.back()->right = cur;
            
            stk.push_back(cur);
            
        }
        
        return stk.front();
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/654.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


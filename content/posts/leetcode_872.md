
+++
authors = ["Yasir"]
title = "Leetcode 872: Leaf-Similar Trees"
date = "2022-06-08"
description = "Solution to Leetcode 872"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/leaf-similar-trees/description/)

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1, s2;
        s1.push(root1), s2.push(root2);
        while(!s1.empty() && !s2.empty())
            if(dfs(s1) != dfs(s2)) return false;
        return s1.empty() && s2.empty();
    }
    
    int dfs(stack<TreeNode*> &stk) {
        while(true) {
            TreeNode* node = stk.top(); stk.pop();
            if(node->left) stk.push(node->left);
            if(node->right) stk.push(node->right);
            if(!node->left && !node->right) return node->val;
        }
    }
};
{{< /highlight >}}


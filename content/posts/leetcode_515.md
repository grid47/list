
+++
authors = ["Crafted by Me"]
title = "Leetcode 515: Find Largest Value in Each Tree Row"
date = "2023-06-05"
description = "Solution to Leetcode 515"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/)

---

{{< youtube 0EVQluJY224 >}}

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
    vector<int> largestValues(TreeNode* root) {
            queue<TreeNode*> q;
        vector<int> res;        
        if(!root) return res;
        q.push(root);
        int mx;

        while(!q.empty()) {
            int sz = q.size();
            mx = INT_MIN;
            while(sz-- > 0) {
                root = q.front();
                q.pop();
                mx = max(mx, root->val);                
                if(root->left)  q.push(root->left);
                if(root->right) q.push(root->right);                
            }
            res.push_back(mx);
        }
        return res;    
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/515.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


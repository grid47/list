
+++
authors = ["Crafted by Me"]
title = "Leetcode 2641: Cousins in Binary Tree II"
date = "2017-08-09"
description = "Solution to Leetcode 2641"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/cousins-in-binary-tree-ii/description/)

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
    TreeNode* replaceValueInTree(TreeNode* root) {
        
        list<TreeNode*> q;
        
        q.push_back(root);
        root->val = 0;
        map<TreeNode*, int> mp;
        while(!q.empty()) {
            int sz = q.size();
            long long sum = 0;
            while(sz--) {
                auto it = q.front();
                q.pop_front();
                if(it->left != NULL) {
                    mp[it] += it->left->val;
                    q.push_back(it->left);
                }
                if(it->right != NULL) {
                    mp[it] += it->right->val;
                    q.push_back(it->right);
                }
                sum += mp[it];
            }
            for(auto it: mp) {
                if(it.first->left != NULL) {
                    it.first->left->val = sum - it.second;
                }
                if(it.first->right != NULL) {
                    it.first->right->val = sum - it.second;
                }    
            }
            mp.clear();
        }
        return root;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


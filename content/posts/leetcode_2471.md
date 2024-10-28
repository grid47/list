
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2471: Minimum Number of Operations to Sort a Binary Tree by Level"
date = "2018-01-23"
description = "Solution to Leetcode 2471"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/description/)

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
        
    int minimumOperations(TreeNode* root) {
        int cnt = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            vector<int> arr, idx(sz);
            while(sz--) {
                auto it = q.front();
                q.pop();
                arr.push_back(it->val);
                if(it->left != NULL) q.push(it->left);
                if(it->right!= NULL) q.push(it->right);
            }
            // cout << sz << " ";
            iota(idx.begin(), idx.end(), 0);
            sort(idx.begin(), idx.end(), [&](int i, int j) { return arr[i] < arr[j]; });
            for(int i = 0; i < idx.size(); i++)
                for(; idx[i] != i; cnt++)
                    swap(idx[i], idx[idx[i]]);
        }
        return cnt;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}



+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1530: Number of Good Leaf Nodes Pairs"
date = "2020-08-22"
description = "Solution to Leetcode 1530"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


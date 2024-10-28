
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 662: Maximum Width of Binary Tree"
date = "2023-01-06"
description = "Solution to Leetcode 662"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-width-of-binary-tree/description/)

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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        int width = 0;
        q.push({root, 0});
        while(!q.empty()) {
            int f = q.front().second;
            int b = q.back().second;
            int cnt = q.size();
            for(int i = 0; i < cnt; i++) {
                TreeNode* elem = q.front().first;
                int idx = q.front().second - b;
                q.pop();
                if(elem->left  != NULL) q.push({elem->left,  2 * idx + 1});
                if(elem->right != NULL) q.push({elem->right, 2 * idx + 2});                
            }
            width = max(width, b - f + 1);
        }
        return width;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


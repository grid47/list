
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2415: Reverse Odd Levels of Binary Tree"
date = "2018-03-21"
description = "Solution to Leetcode 2415"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/)

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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> vals;
        int level = 0;

        while(!q.empty()) {
            int sz = q.size();
            vector<int> temp;
            for(int i = 0; i < sz; i++)  {
                TreeNode* node = q.front(); q.pop();
                if(level %2) node->val= vals[sz- i - 1];
                if(node->left) {
                    q.push(node->left);
                    temp.push_back(node->left->val);
                }

                if(node->right) {
                    q.push(node->right);
                    temp.push_back(node->right->val);
                }
            }
            vals = temp;
            level++;
        }
        return root;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

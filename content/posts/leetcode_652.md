
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 652: Find Duplicate Subtrees"
date = "2023-01-16"
description = "Solution to Leetcode 652"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-duplicate-subtrees/description/)

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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> mp;
        serialise(mp, root);
        vector<TreeNode*> res;
        for(auto it: mp) {
            if(it.second.size() > 1)
            res.push_back(it.second[0]);
        }
        return res;
    }

    string serialise(unordered_map<string, vector<TreeNode*>> &mp, TreeNode* root) {
        if(root == NULL) return "";

        string s = "(" + serialise(mp, root->left) + to_string(root->val) + serialise(mp, root->right) + ")";
        mp[s].push_back(root);
        return s;

    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


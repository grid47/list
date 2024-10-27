
+++
authors = ["Yasir"]
title = "Leetcode 652: Find Duplicate Subtrees"
date = "2023-01-15"
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



+++
authors = ["grid47"]
title = "Leetcode 652: Find Duplicate Subtrees"
date = "2024-09-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 652: Find Duplicate Subtrees in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Binary Tree"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/652.md" >}}
---
{{< youtube kn0Z5_qPPzY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #654: Maximum Binary Tree](https://grid47.xyz/posts/leetcode-654-maximum-binary-tree-solution/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 2476: Closest Nodes Queries in a Binary Search Tree"
date = "2024-03-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2476: Closest Nodes Queries in a Binary Search Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/description/)

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
    vector<int> v;
    void traverse(TreeNode* root) {
        if(root != nullptr) {
            traverse(root->left);
            if(v.empty() || v.back() < root->val)
                v.push_back(root->val);
            traverse(root->right);
        }
    }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        traverse(root);
        vector<vector<int>> res;
        for(int q: queries) {
            auto it = lower_bound(begin(v), end(v), q);
            if(it != end(v) && *it==q)
            res.push_back({q, q});
            else
            res.push_back({it == begin(v)? -1: *prev(it), it == end(v)? -1: *it});
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2476.md" >}}
---
{{< youtube KFYvX7u-Hs8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2477: Minimum Fuel Cost to Report to the Capital](https://grid47.xyz/leetcode/solution-2477-minimum-fuel-cost-to-report-to-the-capital/) |
| --- |

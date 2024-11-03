
+++
authors = ["Crafted by Me"]
title = "Leetcode 2476: Closest Nodes Queries in a Binary Search Tree"
date = "2018-01-22"
description = "In-depth solution and explanation for Leetcode 2476: Closest Nodes Queries in a Binary Search Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2477: Minimum Fuel Cost to Report to the Capital](https://grid47.xyz/posts/leetcode_2477) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


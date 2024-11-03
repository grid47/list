
+++
authors = ["Crafted by Me"]
title = "Leetcode 2196: Create Binary Tree From Descriptions"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2196: Create Binary Tree From Descriptions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/create-binary-tree-from-descriptions/description/)

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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        set<int> s;
        for(vector<int> v: desc) {
            s.insert(v[0]);
            s.insert(v[1]);
        }

        for(auto v: desc) {
            if(s.find(v[1]) != s.end()) {
                s.erase(v[1]);
            }
        }

        int root = *s.begin();

        // found root
        // next create map for nodes
        // connect them as given in desc

        map<int, TreeNode*> mp;
        for(auto v: desc) {
            if(mp.find(v[0]) == mp.end()) {
                mp[v[0]] = new TreeNode(v[0]);
            }
            if(mp.find(v[1]) == mp.end()) {
                mp[v[1]] = new TreeNode(v[1]);
            }
        }

        for(auto v: desc) {
            int paret = v[0];
            int child = v[1];
            int left  = v[2];

            if(left) mp[paret]->left  = mp[child];
            else     mp[paret]->right = mp[child];
        }

        return mp[root];
    }
};
{{< /highlight >}}


---
{{< youtube yWkrFfqO7NA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2197: Replace Non-Coprime Numbers in Array](https://grid47.xyz/posts/leetcode_2197) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}



+++
authors = ["grid47"]
title = "Leetcode 2196: Create Binary Tree From Descriptions"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2196: Create Binary Tree From Descriptions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Tree","Binary Tree"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2196.md" >}}
---
{{< youtube yWkrFfqO7NA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2197: Replace Non-Coprime Numbers in Array](https://grid47.xyz/posts/leetcode-2197-replace-non-coprime-numbers-in-array-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
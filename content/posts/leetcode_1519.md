
+++
authors = ["grid47"]
title = "Leetcode 1519: Number of Nodes in the Sub-Tree With the Same Label"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1519: Number of Nodes in the Sub-Tree With the Same Label in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Breadth-First Search","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
    vector<int> ans;
    vector<int> vst;
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n, 1);
        vst.resize(n, 0);
        vector<vector<int>> adj(n);
        for(auto &e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vst[0] = 1;
        dfs(n, 0, adj, labels);
        return ans;
    }

    vector<int> dfs(int n, int u, vector<vector<int>>& adj, string &labels) {
        vector<int> cnt(26, 0);
        for(auto v: adj[u]) {
            if(vst[v]) continue;

            vst[v] = 1;
            vector<int> sub = dfs(n, v, adj, labels);
            for(int i = 0; i < 26; i++)
                cnt[i] += sub[i];
        }

        cnt[labels[u] - 'a']++;
        ans[u] = cnt[labels[u] - 'a'];
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1519.md" >}}
---
{{< youtube 1vni2K0FIg8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1524: Number of Sub-arrays With Odd Sum](https://grid47.xyz/posts/leetcode_1524) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

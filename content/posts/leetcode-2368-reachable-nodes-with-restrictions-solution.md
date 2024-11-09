
+++
authors = ["grid47"]
title = "Leetcode 2368: Reachable Nodes With Restrictions"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2368: Reachable Nodes With Restrictions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Tree","Depth-First Search","Breadth-First Search","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reachable-nodes-with-restrictions/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
    int ans;
public:
    void solve(vector<vector<int>>& gph, vector<bool> &vis, int i) {
        vis[i] = true;
        for(int n: gph[i]) {
            if(!vis[n]) {
                ans++;
                vis[n] = true;
                solve(gph, vis, n);
            }
        }
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        ans = 1;
        vector<vector<int>> gph(n);
        for(auto e: edges) {
            int u = e[0], v = e[1];
            gph[u].push_back(v);
            gph[v].push_back(u);
        }

        vector<bool> vis(n, false);
        for(auto i: restricted) vis[i] = true;

        solve(gph, vis, 0);
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2368.md" >}}
---
{{< youtube XMF3HhULMbM >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2369: Check if There is a Valid Partition For The Array](https://grid47.xyz/posts/leetcode-2369-check-if-there-is-a-valid-partition-for-the-array-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}


+++
authors = ["grid47"]
title = "Leetcode 2608: Shortest Cycle in a Graph"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2608: Shortest Cycle in a Graph in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Breadth-First Search","Graph"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/shortest-cycle-in-a-graph/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> grid;
    int n;
    int ans = INT_MAX;    
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        this->n = n;
        grid.resize(n);
        for(auto e: edges) {
            grid[e[0]].push_back(e[1]);
            grid[e[1]].push_back(e[0]);
        }

        for(int i = 0; i < n; i++) {
            vector<int> vis(n, INT_MAX);
            dfs(-1, i, 0, vis);
        }
        return ans == INT_MAX? -1: ans;
    }
    
    void dfs(int par, int i, int run, vector<int> &vis) {
        vis[i] = run;
        for(int x: grid[i]) {
            if(x == par) continue;
            if(vis[x] != INT_MAX) {
                ans = min(ans, abs(vis[x] - vis[i]) + 1);
            } else {
                dfs(i, x, run + 1, vis);
            }
        }
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2608.md" >}}
---
{{< youtube R0XznJ91kEw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2609: Find the Longest Balanced Substring of a Binary String](https://grid47.xyz/posts/leetcode-2609-find-the-longest-balanced-substring-of-a-binary-string-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}


+++
authors = ["Crafted by Me"]
title = "Leetcode 2608: Shortest Cycle in a Graph"
date = "2017-09-12"
description = "In-depth solution and explanation for Leetcode 2608: Shortest Cycle in a Graph in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---

| Next : [LeetCode #2609: Find the Longest Balanced Substring of a Binary String](https://grid47.xyz/posts/leetcode_2609) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}



+++
authors = ["Crafted by Me"]
title = "Leetcode 802: Find Eventual Safe States"
date = "2022-08-23"
description = "Solution to Leetcode 802"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-eventual-safe-states/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        vector<int> res;

        int n = graph.size();

        if(n == 0) return res;

        vector<int> vis(n, 0);

        for(int i = 0; i < n; i++)
            if(dfs(graph, i, vis)) res.push_back(i);

        return res;
    }

    int dfs(vector<vector<int>>& graph, int cur, vector<int> &vis) {

        if(vis[cur] != 0) return vis[cur] == 2;

        vis[cur] = 1;
        for(auto nxt: graph[cur])
            if(!dfs(graph, nxt, vis)) return false;

        vis[cur] = 2;

        return true;
    }

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/802.md" >}}
---
{{< youtube Re_v0j0CRsg >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


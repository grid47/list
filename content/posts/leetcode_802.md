
+++
authors = ["Yasir"]
title = "Leetcode 802: Find Eventual Safe States"
date = "2022-08-18"
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

{{< highlight html >}}
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


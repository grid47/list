
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 802: Find Eventual Safe States"
date = "2022-08-19"
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


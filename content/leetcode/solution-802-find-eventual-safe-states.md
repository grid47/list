
+++
authors = ["grid47"]
title = "Leetcode 802: Find Eventual Safe States"
date = "2024-08-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 802: Find Eventual Safe States in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Graph","Topological Sort"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "Re_v0j0CRsg"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/802.webp"
+++



[`Problem Link`](https://leetcode.com/problems/find-eventual-safe-states/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/802.webp" 
    alt="A graph with nodes marked as safe, glowing softly as they are identified."
    caption="Solution to LeetCode 802: Find Eventual Safe States Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #807: Max Increase to Keep City Skyline](https://grid47.xyz/leetcode/solution-807-max-increase-to-keep-city-skyline/) |
| --- |

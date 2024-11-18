
+++
authors = ["grid47"]
title = "Leetcode 1514: Path with Maximum Probability"
date = "2024-06-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1514: Path with Maximum Probability in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Graph","Heap (Priority Queue)","Shortest Path"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "kPsDTGcrzGM"
youtube_upload_date="2023-02-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/kPsDTGcrzGM/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/path-with-maximum-probability/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<pair<int, double>>> grid;
    vector<bool> vis;
    double ans = 0;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& prob, int start, int end) {
        grid.resize(n);
        for(int i = 0; i < edges.size(); i++) {
            grid[edges[i][1]].push_back({edges[i][0], prob[i]});            
            grid[edges[i][0]].push_back({edges[i][1], prob[i]});
        }
        
        priority_queue<pair<double, int>> pq;

        vector<double> mx(n, 0);
        mx[start] = 1;
        vis.resize(n, false);
        // vis[start] = true;
        pq.push({1.0, start});
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            if(!vis[it.second]) {
                vis[it.second] = true;
                for(auto x: grid[it.second]) {
                    if(mx[x.first] < it.first * x.second) {
                        mx[x.first] = it.first * x.second;
                        pq.push({it.first * x.second, x.first});
                    }
                }
            }
        }
        return mx[end];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1514.md" >}}
---
{{< youtube kPsDTGcrzGM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1519: Number of Nodes in the Sub-Tree With the Same Label](https://grid47.xyz/leetcode/solution-1519-number-of-nodes-in-the-sub-tree-with-the-same-label/) |
| --- |

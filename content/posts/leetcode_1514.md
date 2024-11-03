
+++
authors = ["Crafted by Me"]
title = "Leetcode 1514: Path with Maximum Probability"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1514: Path with Maximum Probability in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1515: Best Position for a Service Centre](https://grid47.xyz/posts/leetcode_1515) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


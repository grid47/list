
+++
authors = ["Crafted by Me"]
title = "Leetcode 1514: Path with Maximum Probability"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1514: Path with Maximum Probability in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Graph","Heap (Priority Queue)","Shortest Path"]
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1517: Find Users With Valid E-Mails](https://grid47.xyz/posts/leetcode_1517) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

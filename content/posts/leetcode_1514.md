
+++
authors = ["Crafted by Me"]
title = "Leetcode 1514: Path with Maximum Probability"
date = "2020-09-09"
description = "Solution to Leetcode 1514"
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



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}



+++
authors = ["grid47"]
title = "Leetcode 1976: Number of Ways to Arrive at Destination"
date = "2024-04-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1976: Number of Ways to Arrive at Destination in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Graph","Topological Sort","Shortest Path"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/)

---
**Code:**

{{< highlight cpp >}}
#define ll long long
#define pll pair<ll, ll>

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& rds) {
        vector<vector<pll>> gph(n);
        for(vector<int> &e : rds) {
            int u = e[0], v = e[1], time = e[2];
            gph[u].push_back({v, time});
            gph[v].push_back({u, time});
            
        }
        
        vector<ll> ways(n, 0), dst(n, LLONG_MAX);
        ways[0] = 1;
         dst[0] = 0;
        
        priority_queue<pll, vector<pll>, greater<>> pq;
        
        pq.push({0, 0});
        int ans = 0;
        
        while(!pq.empty()) {
            
          auto [d, u] = pq.top();
          pq.pop();
            
   for(pll nb : gph[u]) {
              int nxt = nb.first, t = nb.second;
       if(dst[nxt] > d + t) {
           
           dst[nxt] = d + t;
           ways[nxt] = ways[u];
           pq.push({d + t, nxt});
       } else if (dst[nxt] == d + t) {
           ways[nxt] = (ways[nxt] + ways[u]) % 1000000007;
       }
       
   }
            
        }
        
        return ways[n - 1];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1976.md" >}}
---
{{< youtube 1JCXqupyLoQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1979: Find Greatest Common Divisor of Array](https://grid47.xyz/posts/leetcode-1979-find-greatest-common-divisor-of-array-solution/) |
| --- |


+++
authors = ["Yasir"]
title = "Leetcode 1976: Number of Ways to Arrive at Destination"
date = "2019-06-01"
description = "Solution to Leetcode 1976"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/)

---

**Code:**

{{< highlight html >}}
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


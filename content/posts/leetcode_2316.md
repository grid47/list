
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2316: Count Unreachable Pairs of Nodes in an Undirected Graph"
date = "2018-06-29"
description = "Solution to Leetcode 2316"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/)

---
{{< youtube 2FIK7F0Qs38 >}}
**Code:**

{{< highlight cpp >}}
class Solution {
    typedef long long ll;
public:
    long long countPairs(int n, vector<vector<int>>& es) {
        
        vector<vector<int>> g(n, vector<int>());
        for(vector<int> e: es){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            
        }
        vector<bool> vis(n, false);
        ll res = (ll) n * (n - 1) /2;
            
        for(int i = 0; i < n; i++) {
            ll ret = 0;
      if(!vis[i])
      ret = dfs(i, g, vis);
      res -= (ret * (ret -1)/2);
        }
        
        return res;
        
    }
    
    ll dfs(int i, vector<vector<int>> &g, vector<bool> &vis) {
        
        if(vis[i]) return 0;
        vis[i] = true;
        ll res = 1;
        for(int v : g[i]) {
            res += dfs(v, g, vis);
        }
        return res;
    }
    
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}



+++
authors = ["grid47"]
title = "Leetcode 2316: Count Unreachable Pairs of Nodes in an Undirected Graph"
date = "2024-03-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2316: Count Unreachable Pairs of Nodes in an Undirected Graph in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/)

---
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2316.md" >}}
---
{{< youtube 2FIK7F0Qs38 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2317: Maximum XOR After Operations ](https://grid47.xyz/posts/leetcode-2317-maximum-xor-after-operations-solution/) |
| --- |

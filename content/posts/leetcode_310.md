
+++
authors = ["Yasir"]
title = "Leetcode 310: Minimum Height Trees"
date = "2023-12-22"
description = "Solution to Leetcode 310"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-height-trees/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for(auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(degree[i] == 1)
                q.push(i);
        
        vector<int> res;
        
        while(!q.empty()) {
            res.clear();
            int sz = q.size();
            while(sz--) {
                int tmp = q.front();
                q.pop();
                res.push_back(tmp);
                for(auto nbr: adj[tmp]) {
                    degree[nbr]--;
                    if(degree[nbr] == 1)
                        q.push(nbr);
                }
            }
        }
        return res;
    }
};
{{< /highlight >}}


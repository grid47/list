
+++
authors = ["Crafted by Me"]
title = "Leetcode 2492: Minimum Score of a Path Between Two Cities"
date = "2018-01-06"
description = "In-depth solution and explanation for Leetcode 2492: Minimum Score of a Path Between Two Cities in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/)

---

**Code:**

{{< highlight cpp >}}
class UF {
    public:
    vector<int> par;
    vector<int> mn;    
    UF(int n) {
        par.resize(n + 1);
        mn.resize(n + 1);        
        for(int i = 1; i < n + 1; i++) {
            par[i] = i;
            mn[i] = INT_MAX;
        }
    }
    
    bool uni(int x, int y, int n) {
        int p = find(x);
        int q = find(y);
        mn[p] = min({mn[p], mn[q], n});
        mn[q] = mn[p];
        if(p == q) return false;
        par[p] = q;
        return true;
    }
    int find(int x) {
        if(par[x] == x) return x;
        mn[x] = mn[find(par[x])];
        return par[x] = find(par[x]);
    }
    int mini(int x) {
        return mn[x];
    }
    bool check(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<vector<int>>> grid(n + 1);

        for(auto it: roads) {
            grid[it[0]].push_back({it[1], it[2]});
            grid[it[1]].push_back({it[0], it[2]});
        }
        
        vector<int> vis(n + 1, false); 
        queue<int> q;
        q.push(1);
        vis[1] = true;
        int mn = INT_MAX;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto it = q.front();
                q.pop();
                for(auto x: grid[it]) {
                        mn = min(mn, x[1]);                    
                    if(!vis[x[0]]) {
                        q.push(x[0]);
                        vis[x[0]] = true;
                    }
                }
            }
        }

        return mn;
    }
    
};
{{< /highlight >}}


---
{{< youtube 7epgOP3ezWM >}}

| Next : [LeetCode #2493: Divide Nodes Into the Maximum Number of Groups](grid47.xyz/leetcode_2493) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


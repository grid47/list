
+++
authors = ["grid47"]
title = "Leetcode 2492: Minimum Score of a Path Between Two Cities"
date = "2024-03-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2492: Minimum Score of a Path Between Two Cities in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Union Find","Graph"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2492.md" >}}
---
{{< youtube 7epgOP3ezWM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2496: Maximum Value of a String in an Array](https://grid47.xyz/posts/leetcode-2496-maximum-value-of-a-string-in-an-array-solution/) |
| --- |

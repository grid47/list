
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1786: Number of Restricted Paths From First to Last Node"
date = "2019-12-10"
description = "Solution to Leetcode 1786"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/description/)

---

**Code:**

{{< highlight cpp >}}
#define pii pair<int, int>

class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& es) {
        
        vector<vector<pii>> gph(n + 1);
        for(int i = 0; i < es.size(); i++) {
            int u = es[i][0], v = es[i][1], d = es[i][2];
            gph[u].push_back({d, v});
            gph[v].push_back({d, u});

        }
        vector<int> dst(n + 1, INT_MAX);
        priority_queue<pii, vector<pii>, greater<>> pq;
        pq.push({0, n});
        dst[n] = 0;
        while(!pq.empty()) {
            
            auto [d, u] = pq.top();
            pq.pop();
            
            for(auto & x: gph[u]) {
                int nxt = x.second, t = x.first;
                
               // if(t != dst[nxt]) continue;
                
                if(dst[nxt] > t + d) {
                    dst[nxt] = t + d;
                    pq.push({t + d, nxt});
                }
            }
            
        }
        vector<int> dp(n + 1, -1);
        return dfs(gph, dst, n, dp);
        
    }
    
    int dfs(vector<vector<pii>> &gph, vector<int> &dst, int s, vector<int> &dp) {
        
        if (s == 1) return 1;
        if (dp[s] != -1) return dp[s];
        
        int mod = 1e9 + 7;
        int sum = 0, w = 0, val = 0;
        for(auto &v : gph[s]) {
            
            w = dst[s];
            val = dst[v.second];
            if (val > w) {
                sum = (sum % mod+ dfs(gph, dst, v.second, dp) % mod) % mod;
            }
            
        }
        return dp[s] = sum % mod;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

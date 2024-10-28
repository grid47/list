
+++
authors = ["Yasir"]
title = "Leetcode 2368: Reachable Nodes With Restrictions"
date = "2018-05-06"
description = "Solution to Leetcode 2368"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reachable-nodes-with-restrictions/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
    int ans;
public:
    void solve(vector<vector<int>>& gph, vector<bool> &vis, int i) {
        vis[i] = true;
        for(int n: gph[i]) {
            if(!vis[n]) {
                ans++;
                vis[n] = true;
                solve(gph, vis, n);
            }
        }
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        ans = 1;
        vector<vector<int>> gph(n);
        for(auto e: edges) {
            int u = e[0], v = e[1];
            gph[u].push_back(v);
            gph[v].push_back(u);
        }

        vector<bool> vis(n, false);
        for(auto i: restricted) vis[i] = true;

        solve(gph, vis, 0);
        return ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


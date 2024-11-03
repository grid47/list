
+++
authors = ["Crafted by Me"]
title = "Leetcode 2368: Reachable Nodes With Restrictions"
date = "2018-05-10"
description = "In-depth solution and explanation for Leetcode 2368: Reachable Nodes With Restrictions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
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


---

| Next : [LeetCode #2369: Check if There is a Valid Partition For The Array](https://grid47.xyz/posts/leetcode_2369) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


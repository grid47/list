
+++
authors = ["Crafted by Me"]
title = "Leetcode 2039: The Time When the Network Becomes Idle"
date = "2019-04-04"
description = "In-depth solution and explanation for Leetcode 2039: The Time When the Network Becomes Idle in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/the-time-when-the-network-becomes-idle/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {

        int n = patience.size();        
        vector<vector<int>> grid(n);
        
        for(auto e: edges) {
            grid[e[0]].push_back(e[1]);
            grid[e[1]].push_back(e[0]);
        }
        
        vector<int> sd(n, INT_MAX); // shortest distance(sd) to master;
        
        sd[0] = 0;
        
        queue<int> q;
        vector<int> vis(n, 0);
        q.push(0);
        vis[0] = 1;
        
        int t = 0;
        while(!q.empty()) {
            int sz = q.size();
                t++;            
            while(sz--) {
                int node = q.front();
                q.pop();
                for(auto it: grid[node]) {
                    if(vis[it]) continue;
                    vis[it] = true;
                    sd[it] = t;
                    q.push(it);
                }
            }
        }
        
        // for(int i = 0; i < n; i++)
        //     cout << sd[i] << " ";
        
        int mx = 0;
        for(int i = 0; i < n; i++) {
            int dist = 2 * sd[i];
            int pat = patience[i];
            if(pat >= dist) {
                mx = max(mx, dist);
            } else {
                
                int mod = dist % pat == 0? pat: dist % pat;
                
                mx = max(mx, dist - mod + dist);
            }
            
        }
        return mx + 1;
        
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #2040: Kth Smallest Product of Two Sorted Arrays](https://grid47.xyz/posts/leetcode_2040) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


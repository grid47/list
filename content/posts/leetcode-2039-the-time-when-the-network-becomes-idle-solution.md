
+++
authors = ["grid47"]
title = "Leetcode 2039: The Time When the Network Becomes Idle"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2039: The Time When the Network Becomes Idle in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Breadth-First Search","Graph"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2039.md" >}}
---
{{< youtube 9URBYJ62lyY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2043: Simple Bank System](https://grid47.xyz/posts/leetcode-2039-the-time-when-the-network-becomes-idle-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

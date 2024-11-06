
+++
authors = ["Crafted by Me"]
title = "Leetcode 743: Network Delay Time"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 743: Network Delay Time in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Graph","Heap (Priority Queue)","Shortest Path"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/network-delay-time/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int, map<int, int>> mp;
        
        for(int i = 0; i < times.size(); i++) {
            mp[times[i][0]][times[i][1]] = times[i][2];
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        vector<int> vis(n + 1, 0);
        pq.push(make_pair(0, k));
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            if(vis[it.second]) continue;
            vis[it.second] = true;
            n--;
            if(n == 0) return it.first;
            
            if(mp.count(it.second))
                for(auto [key, val]: mp[it.second]) {
                    pq.push(make_pair(val + it.first, key));
                }
        }
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/743.md" >}}
---
{{< youtube Bp7STMWMMQw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #744: Find Smallest Letter Greater Than Target](https://grid47.xyz/posts/leetcode_744) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}


+++
authors = ["Yasir"]
title = "Leetcode 743: Network Delay Time"
date = "2022-10-17"
description = "Solution to Leetcode 743"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/network-delay-time/description/)

---

**Code:**

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


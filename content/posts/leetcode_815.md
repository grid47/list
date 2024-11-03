
+++
authors = ["Crafted by Me"]
title = "Leetcode 815: Bus Routes"
date = "2022-08-10"
description = "In-depth solution and explanation for Leetcode 815: Bus Routes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/bus-routes/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, unordered_set<int>> mp;
        
        int n = routes.size();
        vector<vector<int>> bus(n);
        
        for(int i = 0; i < n; i++) {
            for(int x: routes[i]) {
                if(!mp[x].count(i)) {
                    for(auto it: mp[x]) {
                        bus[i].push_back(it);
                        bus[it].push_back(i);
                    }
                }
                mp[x].insert(i);
            }
        }
        if(source == target) return 0;
        int cnt = 0;
        queue<int> q;
        set<int> vis;
        for(int it: mp[source]) {
            q.push(it);
            vis.insert(it);
        }

        while(!q.empty()) {
            cnt++;
            int sz = q.size();
            while(sz--) {
                int x = q.front();
                q.pop();
                if(mp[target].count(x)) return cnt;
                for(auto it: bus[x]) {
                    if(vis.count(it)) continue;
                    vis.insert(it);
                    q.push(it);
                }
            }
        }
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/815.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


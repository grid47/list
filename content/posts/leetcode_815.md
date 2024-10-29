
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 815: Bus Routes"
date = "2022-08-07"
description = "Solution to Leetcode 815"
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


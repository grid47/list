
+++
authors = ["Crafted by Me"]
title = "Leetcode 1615: Maximal Network Rank"
date = "2020-05-31"
description = "Solution to Leetcode 1615"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximal-network-rank/description/)

---

{{< youtube WCfyVhtldoU >}}

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<int> inward(n, 0);
        map<int, set<int>> mp;
        for(auto it: roads) {
            inward[it[0]]++;
            inward[it[1]]++;
            mp[it[0]].insert(it[1]);
            mp[it[1]].insert(it[0]);
        }
        
        int mx = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                mx = max(mx, inward[i] + inward[j] - (mp.count(i) && mp[i].count(j)? 1: 0));
            }
        }
        return mx;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


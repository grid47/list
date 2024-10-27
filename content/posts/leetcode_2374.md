
+++
authors = ["Yasir"]
title = "Leetcode 2374: Node With Highest Edge Score"
date = "2018-04-29"
description = "Solution to Leetcode 2374"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/node-with-highest-edge-score/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int edgeScore(vector<int>& edges) {
        map<int, long long> mp;
        int n = edges.size();
        int mx = -1, idx = -1;
        for(int i = 0; i < n; i++) {
            mp[edges[i]] += i;
            if(mp[edges[i]] > mx) {
                idx = edges[i];
                mx = mp[edges[i]];
            } else if(mp[edges[i]] == mx) {
                if(edges[i] < idx)
                    idx = edges[i];
            }
        }
        return idx;
    }
};
{{< /highlight >}}


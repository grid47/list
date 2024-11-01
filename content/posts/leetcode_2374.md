
+++
authors = ["Crafted by Me"]
title = "Leetcode 2374: Node With Highest Edge Score"
date = "2018-05-04"
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


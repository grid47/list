
+++
authors = ["Crafted by Me"]
title = "Leetcode 853: Car Fleet"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 853: Car Fleet in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Sorting","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/car-fleet/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& v) {
        map<int, double> t;
        for(int i = 0; i < pos.size(); i++) {
            t[-pos[i]] = (double) (target-pos[i]) / v[i];
        }
        
        int fleet = 0;
        double cur = 0;
        
        for(auto it: t) {
            if(it.second > cur) fleet++, cur = it.second;
        }
        return fleet;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/853.md" >}}
---
{{< youtube Pr6T-3yB9RM >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #854: K-Similar Strings](https://grid47.xyz/posts/leetcode_854) |
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

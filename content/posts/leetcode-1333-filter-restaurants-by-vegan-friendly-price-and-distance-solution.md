
+++
authors = ["grid47"]
title = "Leetcode 1333: Filter Restaurants by Vegan-Friendly, Price and Distance"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1333: Filter Restaurants by Vegan-Friendly, Price and Distance in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if(a[1] == b[1]) return a[0] > b[0];
        else return a[1] > b[1];
    }
    
    vector<int> filterRestaurants(vector<vector<int>>& rest, int veg, int mxp, int mxd) {
        
        vector<vector<int>> ans;
        
        for(auto r: rest) {
            if((!veg || (veg == r[2])) && r[3] <= mxp && r[4] <= mxd) {
                ans.push_back({r[0], r[1]});
            }
        }
        
        sort(ans.begin(), ans.end(), cmp);
        
        vector<int> res;
        for(auto x: ans) {
            res.push_back(x[0]);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1333.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1334: Find the City With the Smallest Number of Neighbors at a Threshold Distance](https://grid47.xyz/posts/leetcode-1334-find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
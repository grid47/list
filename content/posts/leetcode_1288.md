
+++
authors = ["grid47"]
title = "Leetcode 1288: Remove Covered Intervals"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1288: Remove Covered Intervals in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-covered-intervals/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& ivl) {
        sort(ivl.begin(), ivl.end());
        int res = 0, left = -1, right = -1;
        
        for(auto p: ivl) {
            if(left < p[0] && right < p[1]) {
                res++;
                left = p[0];
            }
            right = max(p[1], right);
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1288.md" >}}
---
{{< youtube nhAsMabiVkM >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1292: Maximum Side Length of a Square with Sum Less than or Equal to Threshold](https://grid47.xyz/posts/leetcode_1292) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

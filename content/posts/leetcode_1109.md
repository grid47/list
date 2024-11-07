
+++
authors = ["Crafted by Me"]
title = "Leetcode 1109: Corporate Flight Bookings"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1109: Corporate Flight Bookings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/corporate-flight-bookings/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int m) {

        vector<int> ans(m, 0);
        for(auto& v: bookings) {
            ans[v[0] - 1] += v[2];
            if(v[1] < m) ans[v[1]] -= v[2];
        }

        for(int j = 1; j < m; j++)
            ans[j] += ans[j-1];

        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1109.md" >}}
---
{{< youtube geZPsJWEzfc >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1110: Delete Nodes And Return Forest](https://grid47.xyz/posts/leetcode_1110) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

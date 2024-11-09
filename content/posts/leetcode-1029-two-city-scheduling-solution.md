
+++
authors = ["grid47"]
title = "Leetcode 1029: Two City Scheduling"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1029: Two City Scheduling in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/two-city-scheduling/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        /*
        
        2n people - interview
        
        
        */
        int mc = 0;
        vector<int> refund;
        
        for(auto c : costs) {
            mc += c[0];
            refund.push_back(c[1] - c[0]);
        }
        sort(refund.begin(), refund.end());
        int n = costs.size()/ 2;
        
        for(int i = 0; i < n; i++) {
            mc += refund[i];
        }
        
        return mc;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1029.md" >}}
---
{{< youtube d-B_gk_gJtQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1031: Maximum Sum of Two Non-Overlapping Subarrays](https://grid47.xyz/posts/leetcode-1029-two-city-scheduling-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

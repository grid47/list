
+++
authors = ["grid47"]
title = "Leetcode 1854: Maximum Population Year"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1854: Maximum Population Year in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Counting","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-population-year/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> sum(102, 0);
        
        for(auto v: logs) {
            sum[v[1] - 1950]--;
            sum[v[0] - 1950]++;
        }
        
        for(int i = 1; i < 102; i++) {
            sum[i] += sum[i - 1];
            cout << sum[i] << " ";
        }
        
        int mx = 0, yr = 2050;
        for(int i = 101; i >= 0; i--) {
            if(sum[i] >= mx) {
                yr = i + 1950;
                mx = sum[i];
            }
        }
        return yr;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1854.md" >}}
---
{{< youtube 2W2yijatcTY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1855: Maximum Distance Between a Pair of Values](https://grid47.xyz/posts/leetcode-1855-maximum-distance-between-a-pair-of-values-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
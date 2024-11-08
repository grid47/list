
+++
authors = ["grid47"]
title = "Leetcode 1578: Minimum Time to Make Rope Colorful"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1578: Minimum Time to Make Rope Colorful in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int minCost(string colors, vector<int>& cost) {
        
        int res = 0, sum, mx;
        
        int i = 1, n = cost.size();
        
        while(i < n) {
            int e = i;
            sum = cost[e - 1];
            mx = cost[e - 1];
            
            while(e < n && colors[e] == colors[e-1]) {
                sum += cost[e];
                mx = max(mx, cost[e]);
                e++;
            }
            
            res += (sum-mx);
            
            i = e + 1;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1578.md" >}}
---
{{< youtube 9_9jwd2DHMU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1579: Remove Max Number of Edges to Keep Graph Fully Traversable](https://grid47.xyz/posts/leetcode_1579) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

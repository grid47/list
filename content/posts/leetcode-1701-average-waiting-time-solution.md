
+++
authors = ["grid47"]
title = "Leetcode 1701: Average Waiting Time"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1701: Average Waiting Time in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/average-waiting-time/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cust) {
        
        int cur = cust[0][0];
        
        double n = cust.size();
        double sum = 0;
        
        for(int i = 0; i < n; i++) {
            
            if(cur > cust[i][0])
            cur += cust[i][1];
            else
            cur = cust[i][0] + cust[i][1];
            
            sum += cur - cust[i][0];
            
        }
        
        return sum / n;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1701.md" >}}
---
{{< youtube 2fN7uIgCIBA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1702: Maximum Binary String After Change](https://grid47.xyz/posts/leetcode-1701-average-waiting-time-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

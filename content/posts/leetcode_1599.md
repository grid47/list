
+++
authors = ["Crafted by Me"]
title = "Leetcode 1599: Maximum Profit of Operating a Centennial Wheel"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1599: Maximum Profit of Operating a Centennial Wheel in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-profit-of-operating-a-centennial-wheel/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& cust, int boardingCost, int runningCost) {
        
        /*
        
        4gondolas
        couter clockwise
        running cost
        
        */

        int n = cust.size();
        int wait = 0;
        int profit = 0, rot = 0;
        int mx = INT_MIN;
        int idx = 0;
        while(idx < n || wait > 0) {
            wait += idx < n? cust[idx]:0;
            // cout << wait << " ";
            if(wait > 4) {
                profit += 4 * boardingCost - runningCost;
                wait -= 4;
            } else if(wait > 0) {
                profit += wait * boardingCost - runningCost;
                wait = 0;
            }

            if(mx < profit) {
                mx = profit;
                rot = idx + 1;
            }
            idx++;
        }
        return mx <= 0? -1: rot;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1599.md" >}}
---
{{< youtube Jn2ELfoSRf0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1600: Throne Inheritance](https://grid47.xyz/posts/leetcode_1600) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

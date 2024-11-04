
+++
authors = ["Crafted by Me"]
title = "Leetcode 1648: Sell Diminishing-Valued Colored Balls"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1648: Sell Diminishing-Valued Colored Balls in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sell-diminishing-valued-colored-balls/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    int maxProfit(vector<int>& inv, int orders) {
        
        
        long n = inv.size(), res = 0;
        
        sort(inv.rbegin(), inv.rend());
        
        for(int i = 0, col = 1; i < n && orders > 0; i++, col++) {
            long cur = inv[i], prv = i + 1 < n? inv[i + 1]: 0;
            long depth = min((long)orders/col, (long)cur - prv);
            orders -= depth * col;
            
        res = (res + ((cur * (cur + 1) - (cur - depth) * (cur - depth + 1)) / 2 * col)) % mod;
                  
            if(cur - prv > depth) {
                res = (res + orders * (cur - depth)) % mod;
                break;
            }
        }
        
        /*
            There is a value k, for which all the balls above this value are sold.
            
        */
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1648.md" >}}
---
{{< youtube oj7Rxz1r70g >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1649: Create Sorted Array through Instructions](https://grid47.xyz/posts/leetcode_1649) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


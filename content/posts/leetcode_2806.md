
+++
authors = ["Crafted by Me"]
title = "Leetcode 2806: Account Balance After Rounded Purchase"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2806: Account Balance After Rounded Purchase in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/account-balance-after-rounded-purchase/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int accountBalanceAfterPurchase(int val) {
        
        if(val % 10 == 5) val += 5;
        else if(val % 10 > 5) {
            val = val / 10;
            val = (val + 1) * 10;
        } else {
            val = (val / 10) * 10;
        }
        return 100 - val;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2806.md" >}}
---
{{< youtube I3XEMabQJxE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2807: Insert Greatest Common Divisors in Linked List](https://grid47.xyz/posts/leetcode_2807) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

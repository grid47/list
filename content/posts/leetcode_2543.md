
+++
authors = ["Crafted by Me"]
title = "Leetcode 2543: Check if Point Is Reachable"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2543: Check if Point Is Reachable in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Number Theory"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-point-is-reachable/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isReachable(int x, int y) {
        if(x == 1 && y == 1) return true;

        bool ans = false;
        if(y%2 == 0) return isReachable(x, y/2);        
        if(x%2 == 0) return isReachable(x/2, y);        
        if(x > y)    return isReachable(x - y, y);
        if(x < y)    return isReachable(x, y - x);        
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube QD0ZSHeDb8Q >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2544: Alternating Digit Sum](https://grid47.xyz/posts/leetcode_2544) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

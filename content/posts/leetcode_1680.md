
+++
authors = ["Crafted by Me"]
title = "Leetcode 1680: Concatenation of Consecutive Binary Numbers"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1680: Concatenation of Consecutive Binary Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Bit Manipulation","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int concatenatedBinary(int n) {
        
        int mod = (int) 1e9 + 7;
        
        long ans = 0;
        int len = 0;
        for(int i = 1; i <= n; i++) {
            if(__builtin_popcount(i) == 1) len++;
            
            ans = ((ans << len) % mod + i % mod) % mod;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1680.md" >}}
---
{{< youtube 1ZtYzuWUFwA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1681: Minimum Incompatibility](https://grid47.xyz/posts/leetcode_1681) |
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

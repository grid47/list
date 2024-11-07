
+++
authors = ["Crafted by Me"]
title = "Leetcode 1318: Minimum Flips to Make a OR b Equal to c"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1318: Minimum Flips to Make a OR b Equal to c in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int bit(int n, int i) {
        return (n >> i) & 1;
    }
    
    int minFlips(int a, int b, int c) {
        // (a|b) has zero and c has 1 required change is one
        // (a|b) has one and c has zero required change is one(if one of them have 1) or two (if both have one)
        
        /*
            0   0   1       1
            0   1   0       1
            1   0   0       1
            1   1   0       2
        */
        int cnt = 0;
        for(int i = 0; i < 31; i++) {
            if((!bit(a, i) && !bit(b, i) && bit(c, i)) ||
               (!bit(a, i) && bit(b, i) && !bit(c, i)) ||
               (bit(a, i) && !bit(b, i) && !bit(c, i)) ) {
                cnt++;
            } else if((bit(a, i) && bit(b, i) && !bit(c, i))) {
                cnt += 2;
            }
        }
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1318.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1319: Number of Operations to Make Network Connected](https://grid47.xyz/posts/leetcode_1319) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

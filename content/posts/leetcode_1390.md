
+++
authors = ["grid47"]
title = "Leetcode 1390: Four Divisors"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1390: Four Divisors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/four-divisors/description/)

---
**Code:**

{{< highlight cpp >}}


class Solution {
public:

    int sumFourDivisors(vector<int>& nums) {
        
        int sum = 0;
        
        for(auto n: nums) {
            int d = 0;
            for(int i = 2; i * i <= n; i++) {
                if(n % i == 0) {
                    if(d == 0) {
                        d = i;
                    } else {
                        d = 0;
                        break;
                    }
                }
            }
            if(d > 0 && d != n/d) {
                sum += 1 + n + d + n/d;
            }            
        }
        return sum;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1390.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1391: Check if There is a Valid Path in a Grid](https://grid47.xyz/posts/leetcode_1391) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

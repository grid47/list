
+++
authors = ["Crafted by Me"]
title = "Leetcode 1979: Find Greatest Common Divisor of Array"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1979: Find Greatest Common Divisor of Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Number Theory"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    public:
        int gcd(int a, int b) {
            if (b == 0) return a;
            return gcd(b, a % b);
        }
        int findGCD(vector<int> &nums) {
            int min = 1001;
            int max = 0;
            // Find the min and max from array
            for (int e : nums) {
                if (e < min) min = e;
                if (e > max) max = e;
            }
            return gcd(min, max);
        }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1979.md" >}}
---
{{< youtube sJ5pTyUWOZ0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1980: Find Unique Binary String](https://grid47.xyz/posts/leetcode_1980) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

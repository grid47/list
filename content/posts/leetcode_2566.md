
+++
authors = ["Yasir"]
title = "Leetcode 2566: Maximum Difference by Remapping a Digit"
date = "2017-10-20"
description = "Solution to Leetcode 2566"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minMaxDifference(int num) {
        int min_v = num, max_v = num;
        for (int i = 0; i < 10; ++i) {
            int lo = 0, hi = 0, mul = 1;
            for (int n = num; n; n /= 10) {
                bool replace = n % 10 == i;
                lo += (replace ? 0 : n % 10) * mul;
                hi += (replace ? 9 : n % 10) * mul;
                mul *= 10;
            }
            min_v = min(min_v, lo);
            max_v = max(max_v, hi);
        }
        return max_v - min_v;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


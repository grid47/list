
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 29: Divide Two Integers"
date = "2024-10-01"
description = "Solution to Leetcode 29"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/divide-two-integers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        long dvd = labs(dividend), dvs = labs(divisor);
        int sgn = (dividend > 0) ^ (divisor > 0) ? -1: 1;
        long ans = 0;

        while( dvd >= dvs ) {
            long tmp = dvs, m = 1;
            while(tmp << 1 <= dvd) {
                tmp <<= 1;
                m <<= 1;
            }
            dvd -= tmp;
            ans += m;
        }

        return sgn * ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/29.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


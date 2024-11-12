
+++
authors = ["grid47"]
title = "Leetcode 29: Divide Two Integers"
date = "2024-11-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 29: Divide Two Integers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/divide-two-integers/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/29.webp" 
    alt="Two smooth, glowing beams dividing and separating in perfect balance."
    caption="Solution to LeetCode 29: Divide Two Integers Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
---
{{< youtube LzcSE7-m6vY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #31: Next Permutation](https://grid47.xyz/posts/leetcode-31-next-permutation-solution/) |
| --- |

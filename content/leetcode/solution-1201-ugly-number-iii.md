
+++
authors = ["grid47"]
title = "Leetcode 1201: Ugly Number III"
date = "2024-07-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1201: Ugly Number III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Binary Search","Combinatorics","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/ugly-number-iii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int nthUglyNumber(int k, int A, int B, int C) {
        int lo = 1, hi = 2* (int)1e9;
        long a = long(A), b = long(B), c = long(C);
        long ab = a * b / __gcd(a, b);
        long bc = b * c / __gcd(b, c);
        long ac = a * c / __gcd(a, c);
        long abc = a * bc / __gcd(a, bc);
        while (lo < hi ) {
            int mid = lo + (hi - lo)/2;
            int cnt = mid / a + mid / b + mid / c - mid / ab - mid / bc - mid / ac + mid / abc;
            
            if (cnt < k) {
                lo = mid + 1;
            } else hi = mid;
        }
        return lo;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1201.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1202: Smallest String With Swaps](https://grid47.xyz/leetcode/solution-1202-smallest-string-with-swaps/) |
| --- |

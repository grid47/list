
+++
authors = ["Crafted by Me"]
title = "Leetcode 1201: Ugly Number III"
date = "2021-07-19"
description = "Solution to Leetcode 1201"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


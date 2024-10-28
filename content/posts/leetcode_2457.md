
+++
authors = ["Yasir"]
title = "Leetcode 2457: Minimum Addition to Make Integer Beautiful"
date = "2018-02-06"
description = "Solution to Leetcode 2457"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:

    int sum(long long n) {
        int res = 0;
        while(n > 0) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }

    long long makeIntegerBeautiful(long long n, int target) {
        long long n0 = n, base = 1;
        while(sum(n) > target) {
            n = n / 10 + 1;
            base *= 10;
        }
        return n * base - n0;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


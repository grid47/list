
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1979: Find Greatest Common Divisor of Array"
date = "2019-05-31"
description = "Solution to Leetcode 1979"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


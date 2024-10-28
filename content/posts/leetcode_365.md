
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 365: Water and Jug Problem"
date = "2023-10-30"
description = "Solution to Leetcode 365"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/water-and-jug-problem/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x + y < z) return false;
        if(x == z || y == z || x + y == z) return true;
        return z % gcd(x, y) == 0;
    }

    int gcd(int a, int b) {
        return b == 0? a: gcd(b, a%b);
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


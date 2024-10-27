
+++
authors = ["Yasir"]
title = "Leetcode 365: Water and Jug Problem"
date = "2023-10-29"
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

{{< highlight html >}}
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


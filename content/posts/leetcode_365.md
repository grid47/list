
+++
authors = ["Crafted by Me"]
title = "Leetcode 365: Water and Jug Problem"
date = "2023-11-03"
description = "In-depth solution and explanation for Leetcode 365: Water and Jug Problem in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/365.md" >}}
---

| Next : [LeetCode #366: Find Leaves of Binary Tree](https://grid47.xyz/posts/leetcode_366) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


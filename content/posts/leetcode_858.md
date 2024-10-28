
+++
authors = ["Yasir"]
title = "Leetcode 858: Mirror Reflection"
date = "2022-06-24"
description = "Solution to Leetcode 858"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/mirror-reflection/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int mirrorReflection(int p, int q) {
        while( p % 2 == 0 && q % 2 == 0) p >>= 1, q >>= 1;
        return 1 - p%2 + q%2;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


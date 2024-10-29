
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 858: Mirror Reflection"
date = "2022-06-25"
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

{{< highlight cpp >}}
class Solution {
public:
    int mirrorReflection(int p, int q) {
        while( p % 2 == 0 && q % 2 == 0) p >>= 1, q >>= 1;
        return 1 - p%2 + q%2;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/858.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


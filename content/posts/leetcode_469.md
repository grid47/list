
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 469: Convex Polygon"
date = "2023-07-18"
description = "Solution to Leetcode 469"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/convex-polygon/description/)

---

**Code:**

{{< highlight cpp >}}
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int result = 40;
        while(result >= 40) { result = (7 * (rand7() - 1)) + (rand7() -1); }
        return result % 10 + 1;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


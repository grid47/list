
+++
authors = ["Yasir"]
title = "Leetcode 469: Convex Polygon"
date = "2023-07-17"
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

{{< highlight html >}}
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


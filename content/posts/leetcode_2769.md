
+++
authors = ["Yasir"]
title = "Leetcode 2769: Find the Maximum Achievable Number"
date = "2017-03-30"
description = "Solution to Leetcode 2769"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-maximum-achievable-number/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + 2 * t;
    }
};
{{< /highlight >}}


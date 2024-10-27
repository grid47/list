
+++
authors = ["Yasir"]
title = "Leetcode 1227: Airplane Seat Assignment Probability"
date = "2021-06-19"
description = "Solution to Leetcode 1227"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/airplane-seat-assignment-probability/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n == 1) return 1;
        return 1/2.0;
    }
};
{{< /highlight >}}


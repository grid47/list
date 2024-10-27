
+++
authors = ["Yasir"]
title = "Leetcode 2651: Calculate Delayed Arrival Time"
date = "2017-07-26"
description = "Solution to Leetcode 2651"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/calculate-delayed-arrival-time/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int findDelayedArrivalTime(int at, int dt) {
        return (at + dt) % 24;
    }
};
{{< /highlight >}}


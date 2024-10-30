
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2651: Calculate Delayed Arrival Time"
date = "2017-07-29"
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
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findDelayedArrivalTime(int at, int dt) {
        return (at + dt) % 24;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


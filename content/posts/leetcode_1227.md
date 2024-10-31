
+++
authors = ["Crafted by Me"]
title = "Leetcode 1227: Airplane Seat Assignment Probability"
date = "2021-06-23"
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

{{< highlight cpp >}}
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n == 1) return 1;
        return 1/2.0;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


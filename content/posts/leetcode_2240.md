
+++
authors = ["Yasir"]
title = "Leetcode 2240: Number of Ways to Buy Pens and Pencils"
date = "2018-09-11"
description = "Solution to Leetcode 2240"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long cnt = 0;
        int sum = total;
        while(sum >= 0 || sum/cost2 > 0) {
            cnt+= (sum/cost2 + 1);
            sum -= cost1;
        }
        return cnt;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


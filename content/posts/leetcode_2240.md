
+++
authors = ["Crafted by Me"]
title = "Leetcode 2240: Number of Ways to Buy Pens and Pencils"
date = "2017-09-14"
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


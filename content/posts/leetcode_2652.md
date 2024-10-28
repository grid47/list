
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2652: Sum Multiples"
date = "2017-07-26"
description = "Solution to Leetcode 2652"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-multiples/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumOfMultiples(int n) {
        int sum = 0;
        for(int i = 1; i <= n; i++)
            if((i % 3 == 0) || (i% 5 == 0) || (i % 7 == 0))
                sum += i;
        return sum;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


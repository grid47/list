
+++
authors = ["Yasir"]
title = "Leetcode 2652: Sum Multiples"
date = "2017-07-25"
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

{{< highlight html >}}
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


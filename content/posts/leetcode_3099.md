
+++
authors = ["Yasir"]
title = "Leetcode 3099: Harshad Number"
date = "2016-05-04"
description = "Solution to Leetcode 3099"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/harshad-number/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0;
        int tmp = x;
        while(tmp > 0) {
            sum += tmp % 10;
            tmp /= 10;
        }
        return x % sum == 0? sum : -1;
    }
};
{{< /highlight >}}


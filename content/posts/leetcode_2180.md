
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2180: Count Integers With Even Digit Sum"
date = "2018-11-10"
description = "Solution to Leetcode 2180"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-integers-with-even-digit-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countEven(int num) {
        int temp = num, sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum % 2 == 0 ? temp / 2 : (temp - 1) / 2;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


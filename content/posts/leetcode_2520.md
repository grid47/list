
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2520: Count the Digits That Divide a Number"
date = "2017-12-07"
description = "Solution to Leetcode 2520"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-the-digits-that-divide-a-number/description/)

---
{{< youtube 7SHHsS5kPJ8 >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countDigits(int num) {
        int res = 0;
        for (int n = num; n > 0; n /= 10)
            res += num % (n % 10) == 0;
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


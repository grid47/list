
+++
authors = ["Yasir"]
title = "Leetcode 2469: Convert the Temperature"
date = "2018-01-25"
description = "Solution to Leetcode 2469"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/convert-the-temperature/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return { celsius + 273.15, celsius*1.80 + 32.00 };
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}



+++
authors = ["Yasir"]
title = "Leetcode 2469: Convert the Temperature"
date = "2018-01-24"
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


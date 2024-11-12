
+++
authors = ["grid47"]
title = "Leetcode 2469: Convert the Temperature"
date = "2024-03-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2469: Convert the Temperature in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/convert-the-temperature/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return { celsius + 273.15, celsius*1.80 + 32.00 };
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2469.md" >}}
---
{{< youtube pJo95i-uamg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2470: Number of Subarrays With LCM Equal to K](https://grid47.xyz/posts/leetcode-2470-number-of-subarrays-with-lcm-equal-to-k-solution/) |
| --- |

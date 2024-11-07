
+++
authors = ["Crafted by Me"]
title = "Leetcode 2469: Convert the Temperature"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2470: Number of Subarrays With LCM Equal to K](https://grid47.xyz/posts/leetcode_2470) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

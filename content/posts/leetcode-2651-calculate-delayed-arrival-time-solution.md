
+++
authors = ["grid47"]
title = "Leetcode 2651: Calculate Delayed Arrival Time"
date = "2024-02-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2651: Calculate Delayed Arrival Time in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/calculate-delayed-arrival-time/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findDelayedArrivalTime(int at, int dt) {
        return (at + dt) % 24;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2651.md" >}}
---
{{< youtube 8a04uEm1FlE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2652: Sum Multiples](https://grid47.xyz/posts/leetcode-2652-sum-multiples-solution/) |
| --- |

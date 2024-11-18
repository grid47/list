
+++
authors = ["grid47"]
title = "Leetcode 1732: Find the Highest Altitude"
date = "2024-05-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1732: Find the Highest Altitude in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-highest-altitude/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx = 0;
        int cur = 0;
        for(int x: gain) {
            cur += x;
            mx = max(mx, cur);
        }
        return mx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1732.md" >}}
---
{{< youtube rizlq7r8_Zg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1733: Minimum Number of People to Teach](https://grid47.xyz/leetcode/solution-1733-minimum-number-of-people-to-teach/) |
| --- |

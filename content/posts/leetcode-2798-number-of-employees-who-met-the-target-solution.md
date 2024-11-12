
+++
authors = ["grid47"]
title = "Leetcode 2798: Number of Employees Who Met the Target"
date = "2024-02-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2798: Number of Employees Who Met the Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-employees-who-met-the-target/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int cnt = 0;
        for(int i = 0; i < hours.size(); i++)
            if(hours[i] >= target) cnt++;
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2798.md" >}}
---
{{< youtube 2AJL4Oh1snk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2799: Count Complete Subarrays in an Array](https://grid47.xyz/posts/leetcode-2799-count-complete-subarrays-in-an-array-solution/) |
| --- |

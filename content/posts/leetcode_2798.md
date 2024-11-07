
+++
authors = ["Crafted by Me"]
title = "Leetcode 2798: Number of Employees Who Met the Target"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2799: Count Complete Subarrays in an Array](https://grid47.xyz/posts/leetcode_2799) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

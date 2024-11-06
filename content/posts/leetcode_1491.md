
+++
authors = ["Crafted by Me"]
title = "Leetcode 1491: Average Salary Excluding the Minimum and Maximum Salary"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1491: Average Salary Excluding the Minimum and Maximum Salary in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    double average(vector<int>& nums) {
        int n = nums.size();
        double sum = 0, mx = nums[0], mn = nums[0];
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            mx = max((double)nums[i], mx);
            mn = min((double)nums[i], mn);
        }
        return (sum - mx - mn) / (n - 2);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1491.md" >}}
---
{{< youtube hTEVGYRGLsQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1492: The kth Factor of n](https://grid47.xyz/posts/leetcode_1492) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

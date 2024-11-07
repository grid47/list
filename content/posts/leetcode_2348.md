
+++
authors = ["Crafted by Me"]
title = "Leetcode 2348: Number of Zero-Filled Subarrays"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2348: Number of Zero-Filled Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-zero-filled-subarrays/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        for(int i = 0, j = 0; i < nums.size(); i++) {
            if(nums[i] != 0)
            j = i +1;
            res += i + 1 - j;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2348.md" >}}
---
{{< youtube 1Y_QfTQmfKg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2349: Design a Number Container System](https://grid47.xyz/posts/leetcode_2349) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}


+++
authors = ["Crafted by Me"]
title = "Leetcode 209: Minimum Size Subarray Sum"
date = "2024-04-07"
description = "In-depth solution and explanation for Leetcode 209: Minimum Size Subarray Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-size-subarray-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, idx = 0, g = INT_MAX, bdx = 0;
        while(idx < nums.size()) {
            sum += nums[idx];

            while(sum >= target) {
                g = min(g, idx - bdx + 1);
                sum -= nums[bdx];
                bdx++;
            }
            idx++;
        }
        return g == INT_MAX? 0: g;
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/209.md" >}}
---
{{< youtube RG17VCQOFpg >}}

"| 210: Course Schedule II |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


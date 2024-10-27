
+++
authors = ["Yasir"]
title = "Leetcode 209: Minimum Size Subarray Sum"
date = "2024-04-02"
description = "Solution to Leetcode 209"
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

{{< highlight html >}}
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


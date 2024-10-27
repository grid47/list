
+++
authors = ["Yasir"]
title = "Leetcode 2401: Longest Nice Subarray"
date = "2018-04-02"
description = "Solution to Leetcode 2401"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-nice-subarray/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res = 1, AND = 0, n = nums.size(), j = 0;
        for(int i = 0; i < n; i++) {
            while(((AND & nums[i]) > 0)) {
                AND ^= nums[j++];
            }
            AND |= nums[i];
            res = max(res, i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}


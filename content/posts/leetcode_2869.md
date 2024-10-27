
+++
authors = ["Yasir"]
title = "Leetcode 2869: Minimum Operations to Collect Elements"
date = "2016-12-20"
description = "Solution to Leetcode 2869"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-collect-elements/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt[51] = {}, i = nums.size() - 1;
        for (int found = 0; found < k; --i)
            if (nums[i] <= k)
                found += cnt[nums[i]]++ == 0;
        return nums.size() - i - 1;
    }
};
{{< /highlight >}}



+++
authors = ["Yasir"]
title = "Leetcode 2470: Number of Subarrays With LCM Equal to K"
date = "2018-01-23"
description = "Solution to Leetcode 2470"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n && k % nums[j] == 0; j++) {
                nums[i] = (nums[i] * nums[j] / __gcd(nums[i], nums[j]));
                cnt += nums[i] == k;
            }
        }
        return cnt;
    }
};
{{< /highlight >}}


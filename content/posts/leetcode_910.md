
+++
authors = ["Yasir"]
title = "Leetcode 910: Smallest Range II"
date = "2022-05-01"
description = "Solution to Leetcode 910"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-range-ii/description/)

---

**Code:**

{{< highlight html >}}
class Solution {

public:
    int smallestRangeII(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size(), left = nums[0] + k, right = nums[n - 1] - k;
        
        int res = nums[n - 1] - nums[0];
        for(int i = 0; i < n - 1; i++) {
            int maxi = max(nums[i] + k, right);
            int mini = min(nums[i + 1] - k, left);
            res = min(res, maxi - mini);
        }
        
        return res;
    }
    
};
{{< /highlight >}}


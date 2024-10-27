
+++
authors = ["Yasir"]
title = "Leetcode 2567: Minimum Score by Changing Two Elements"
date = "2017-10-18"
description = "Solution to Leetcode 2567"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-score-by-changing-two-elements/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        int a = nums[n - 3] - nums[0];
        int b = nums[n - 1] - nums[2];
        int c = nums[n - 2] - nums[1];
        return min({a, b, c});
        
    }
};
{{< /highlight >}}


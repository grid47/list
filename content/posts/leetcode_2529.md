
+++
authors = ["Yasir"]
title = "Leetcode 2529: Maximum Count of Positive Integer and Negative Integer"
date = "2017-11-25"
description = "Solution to Leetcode 2529"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] > 0) pos++;
            else if(nums[i] < 0) neg++;
        return max(pos, neg);
    }
};
{{< /highlight >}}


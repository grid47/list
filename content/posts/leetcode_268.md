
+++
authors = ["Yasir"]
title = "Leetcode 268: Missing Number"
date = "2024-02-03"
description = "Solution to Leetcode 268"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/missing-number/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++)
            sum ^= nums[i];
        for(int i = 0; i <= nums.size(); i++)
            sum ^= i;
        return sum;
    }
};
{{< /highlight >}}


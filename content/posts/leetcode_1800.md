
+++
authors = ["Yasir"]
title = "Leetcode 1800: Maximum Ascending Subarray Sum"
date = "2019-11-24"
description = "Solution to Leetcode 1800"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-ascending-subarray-sum/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int maxi = sum;
        if(nums.size() == 1) return nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= nums[i-1]){
                sum = 0;
            }
                sum += nums[i];
                maxi = max(sum,maxi);
        }
            return maxi;
        }
    
};
{{< /highlight >}}


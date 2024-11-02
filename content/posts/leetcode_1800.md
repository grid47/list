
+++
authors = ["Crafted by Me"]
title = "Leetcode 1800: Maximum Ascending Subarray Sum"
date = "2018-11-28"
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


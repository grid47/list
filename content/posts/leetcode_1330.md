
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1330: Reverse Subarray To Maximize Array Value"
date = "2021-03-11"
description = "Solution to Leetcode 1330"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size();
        int net = 0;
        for(int i =1; i < n; i++)
            net += abs(nums[i] - nums[i - 1]);
        
        int res = INT_MIN, mn = INT_MAX, mx = INT_MIN;
        for(int i = 0; i < n - 1; i++) {
            res = max(res, abs(nums[0] - nums[i + 1]) - abs(nums[i] - nums[i + 1]));
            res = max(res, abs(nums[n - 1] - nums[i]) - abs(nums[i] - nums[i + 1]));
            mn = min(max(nums[i], nums[i + 1]), mn);
            mx = max(min(nums[i], nums[i + 1]), mx);
        }
        
        return net + max(res, (mx - mn) * 2);
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


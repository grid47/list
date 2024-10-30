
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2470: Number of Subarrays With LCM Equal to K"
date = "2018-01-26"
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
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


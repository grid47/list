
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2348: Number of Zero-Filled Subarrays"
date = "2018-05-27"
description = "Solution to Leetcode 2348"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-zero-filled-subarrays/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        for(int i = 0, j = 0; i < nums.size(); i++) {
            if(nums[i] != 0)
            j = i +1;
            res += i + 1 - j;
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

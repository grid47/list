
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1480: Running Sum of 1d Array"
date = "2020-10-10"
description = "Solution to Leetcode 1480"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/running-sum-of-1d-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++)
            nums[i] += nums[i - 1];
        return nums;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


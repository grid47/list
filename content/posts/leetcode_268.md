
+++
authors = ["Yasir"]
title = "Leetcode 268: Missing Number"
date = "2024-02-04"
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


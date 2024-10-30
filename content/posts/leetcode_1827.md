
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1827: Minimum Operations to Make the Array Increasing"
date = "2019-10-31"
description = "Solution to Leetcode 1827"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0, need = nums[0] + 1;
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            res += max(0, need - nums[i]);
            need = max(nums[i], need) + 1;
        }
        
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


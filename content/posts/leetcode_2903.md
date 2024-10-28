
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2903: Find Indices With Index and Value Difference I"
date = "2016-11-17"
description = "Solution to Leetcode 2903"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-indices-with-index-and-value-difference-i/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int idif, int vdif) {

        int mn = 0, mx = 0;
        for (int i = idif, j = 0; i < nums.size(); ++i, ++j) {
            mn = nums[mn] < nums[j] ? mn : j;
            mx = nums[mx] > nums[j] ? mx : j;
            if (abs(nums[i] - nums[mn]) >= vdif)
                return {mn, i};
            if (abs(nums[i] - nums[mx]) >= vdif)
                return {mx, i};
        }
        return {-1, -1};        

    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


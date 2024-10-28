
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 34: Find First and Last Position of Element in Sorted Array"
date = "2024-09-25"
description = "Solution to Leetcode 34"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        auto it1 = lower_bound(nums.begin(), nums.end(), target);
        auto it2 = upper_bound(nums.begin(), nums.end(), target);

        if(it1 == nums.end() || *it1 != target) return {-1, -1};

        return {(int) (it1 - nums.begin()), (int) (it2 - nums.begin() - 1)};
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


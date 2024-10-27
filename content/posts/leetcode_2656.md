
+++
authors = ["Yasir"]
title = "Leetcode 2656: Maximum Sum With Exactly K Elements "
date = "2017-07-21"
description = "Solution to Leetcode 2656"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int i = *max_element(nums.begin(), nums.end());
        return i * k + k * (k - 1) / 2;
    }
};
{{< /highlight >}}


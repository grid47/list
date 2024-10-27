
+++
authors = ["Yasir"]
title = "Leetcode 2395: Find Subarrays With Equal Sum"
date = "2018-04-08"
description = "Solution to Leetcode 2395"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-subarrays-with-equal-sum/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
    unordered_set<int> s;
    for (int i = 1; i < nums.size(); ++i)
        if(!s.insert(nums[i - 1] + nums[i]).second)
            return true;
    return false;
  }
};
{{< /highlight >}}


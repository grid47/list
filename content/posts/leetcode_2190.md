
+++
authors = ["Yasir"]
title = "Leetcode 2190: Most Frequent Number Following Key In an Array"
date = "2018-10-30"
description = "Solution to Leetcode 2190"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
  int mostFrequent(vector<int>& nums, int key) {
    int cnt[1001] = {}, res = 0;
    for (int i = 1; i < nums.size(); ++i)
        if (nums[i - 1] == key && ++cnt[nums[i]] > cnt[res])
            res = nums[i];
    return res;
  }
};
{{< /highlight >}}


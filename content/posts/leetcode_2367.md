
+++
authors = ["Yasir"]
title = "Leetcode 2367: Number of Arithmetic Triplets"
date = "2018-05-06"
description = "Solution to Leetcode 2367"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-arithmetic-triplets/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
    int cnt[201] = {}, res = 0;
    for (auto n : nums) {
        if (n >= 2 * diff)
            res += cnt[n - diff] && cnt[n - 2 * diff];
        cnt[n] = true;
    }
    return res;
  }
};
{{< /highlight >}}



+++
authors = ["Yasir"]
title = "Leetcode 2874: Maximum Value of an Ordered Triplet II"
date = "2016-12-15"
description = "Solution to Leetcode 2874"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long res = 0, n = nums.size();
        long maxa = 0, maxab = 0;
        for(int a: nums) {
            res = max(res, 1L * maxab * a);
            maxab = max(maxab, (long) maxa - a);
            maxa = max(maxa, (long)a);
        }
        return res;
    }
};
{{< /highlight >}}


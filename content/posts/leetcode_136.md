
+++
authors = ["Yasir"]
title = "Leetcode 136: Single Number"
date = "2024-06-13"
description = "Solution to Leetcode 136"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/single-number/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(int y: nums)
            x ^= y;
        return x;
    }
};
{{< /highlight >}}


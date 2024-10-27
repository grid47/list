
+++
authors = ["Yasir"]
title = "Leetcode 1863: Sum of All Subset XOR Totals"
date = "2019-09-22"
description = "Solution to Leetcode 1863"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        for (auto i = 1; i < (1 << nums.size()); ++i) {
            int total = 0;
            for (auto j = 0; j < nums.size(); ++j)
                if (i & (1 << j))
                    total ^= nums[j];
            res += total;
        }
        return res;
    }
};
{{< /highlight >}}


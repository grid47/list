
+++
authors = ["Yasir"]
title = "Leetcode 2870: Minimum Number of Operations to Make Array Empty"
date = "2016-12-19"
description = "Solution to Leetcode 2870"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n : nums)
            ++m[n];
        int res = 0;
        for (auto [_, cnt] : m) {
            if (cnt == 1)
                return -1;
            res += cnt / 3 + (cnt % 3 > 0);
        }
        return res;
    }
};
{{< /highlight >}}



+++
authors = ["Yasir"]
title = "Leetcode 2475: Number of Unequal Triplets in Array"
date = "2018-01-18"
description = "Solution to Leetcode 2475"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-unequal-triplets-in-array/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
int unequalTriplets(vector<int>& nums) {
    unordered_map<int, int> m;
    for (int n : nums)
        ++m[n];
    int res = 0, left = 0, right = nums.size();
    for (auto [n, cnt] : m) {
        right -= cnt;
        res += left * cnt * right;
        left += cnt;
    }
    return res;
}
};
{{< /highlight >}}


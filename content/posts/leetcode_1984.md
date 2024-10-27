
+++
authors = ["Yasir"]
title = "Leetcode 1984: Minimum Difference Between Highest and Lowest of K Scores"
date = "2019-05-24"
description = "Solution to Leetcode 1984"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
int minimumDifference(vector<int>& nums, int k) {
    int res = INT_MAX;
    sort(begin(nums), end(nums));
    for (int i = k - 1; i < nums.size(); ++i)
        res = min(res, nums[i] - nums[i - k + 1]);
    return res;
}
};
{{< /highlight >}}


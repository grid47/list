
+++
authors = ["Crafted by Me"]
title = "Leetcode 1984: Minimum Difference Between Highest and Lowest of K Scores"
date = "2019-05-29"
description = "In-depth solution and explanation for Leetcode 1984: Minimum Difference Between Highest and Lowest of K Scores in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
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


---
{{< youtube JU5XdBZZtlk >}}

| Next : [LeetCode #1985: Find the Kth Largest Integer in the Array](grid47.xyz/leetcode_1985) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


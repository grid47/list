
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1984: Minimum Difference Between Highest and Lowest of K Scores"
date = "2019-05-25"
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


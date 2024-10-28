
+++
authors = ["Yasir"]
title = "Leetcode 2006: Count Number of Pairs With Absolute Difference K"
date = "2019-05-03"
description = "Solution to Leetcode 2006"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int cnt[101] = {}, res = 0;
        for (auto n : nums)
            ++cnt[n];
        for (int i = k + 1; i < 101; ++i)
            res += cnt[i] * cnt[i - k];
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


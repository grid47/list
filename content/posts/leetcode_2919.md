
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2919: Minimum Increment Operations to Make Array Beautiful"
date = "2016-11-01"
description = "Solution to Leetcode 2919"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-increment-operations-to-make-array-beautiful/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long minIncrementOperations(vector<int>& A, int k) {
        long long dp1 = 0, dp2 = 0, dp3 = 0, dp;
        for (int& a: A) {
            dp = min(dp1, min(dp2, dp3)) + max(k - a, 0);
            dp1 = dp2;
            dp2 = dp3;
            dp3 = dp;
        }
        return min(dp1, min(dp2, dp3));
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


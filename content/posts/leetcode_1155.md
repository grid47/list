
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1155: Number of Dice Rolls With Target Sum"
date = "2021-09-01"
description = "Solution to Leetcode 1155"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int dp[31][1001] = {};
    int numRollsToTarget(int d, int f, int target, int res = 0) {
        if (d == 0 || target <= 0) return d == target;
        if (dp[d][target]) return dp[d][target] - 1;
        for (auto i = 1; i <= f; ++i)
            res = (res + numRollsToTarget(d - 1, f, target - i)) % 1000000007;
        dp[d][target] = res + 1;
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


+++
authors = ["Crafted by Me"]
title = "Leetcode 1155: Number of Dice Rolls With Target Sum"
date = "2021-09-04"
description = "In-depth solution and explanation for Leetcode 1155: Number of Dice Rolls With Target Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1155.md" >}}
---
{{< youtube y1PUOTOr-qU >}}
| Next : [LeetCode #1156: Swap For Longest Repeated Character Substring](https://grid47.xyz/posts/leetcode_1156) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


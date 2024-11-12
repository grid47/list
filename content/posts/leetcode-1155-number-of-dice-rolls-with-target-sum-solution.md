
+++
authors = ["grid47"]
title = "Leetcode 1155: Number of Dice Rolls With Target Sum"
date = "2024-07-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1155: Number of Dice Rolls With Target Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming"]
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1156: Swap For Longest Repeated Character Substring](https://grid47.xyz/posts/leetcode-1156-swap-for-longest-repeated-character-substring-solution/) |
| --- |

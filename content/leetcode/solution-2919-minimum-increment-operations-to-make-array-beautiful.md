
+++
authors = ["grid47"]
title = "Leetcode 2919: Minimum Increment Operations to Make Array Beautiful"
date = "2024-01-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2919: Minimum Increment Operations to Make Array Beautiful in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "2T14Nl0I69A"
img_src = ""
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2919.md" >}}
---
{{< youtube 2T14Nl0I69A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2923: Find Champion I](https://grid47.xyz/leetcode/solution-2923-find-champion-i/) |
| --- |

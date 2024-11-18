
+++
authors = ["grid47"]
title = "Leetcode 2767: Partition String Into Minimum Beautiful Substrings"
date = "2024-02-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2767: Partition String Into Minimum Beautiful Substrings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Dynamic Programming","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/partition-string-into-minimum-beautiful-substrings/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
        int minimumBeautifulSubstrings(string s) {
        int n = s.length();
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') continue;
            for (int j = i, cur = 0; j < n; j++) {
                cur = cur * 2 + s[j] - '0';
                if (15625 % cur == 0)
                    dp[j + 1] = min(dp[j + 1], dp[i] + 1);
            }
        }
        return dp[n] > n ? -1 : dp[n];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2767.md" >}}
---
{{< youtube xV-TA-TtiAg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2768: Number of Black Blocks](https://grid47.xyz/leetcode/solution-2768-number-of-black-blocks/) |
| --- |

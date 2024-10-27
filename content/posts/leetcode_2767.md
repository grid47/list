
+++
authors = ["Yasir"]
title = "Leetcode 2767: Partition String Into Minimum Beautiful Substrings"
date = "2017-04-01"
description = "Solution to Leetcode 2767"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/partition-string-into-minimum-beautiful-substrings/description/)

---

**Code:**

{{< highlight html >}}
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


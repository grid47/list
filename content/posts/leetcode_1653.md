
+++
authors = ["Yasir"]
title = "Leetcode 1653: Minimum Deletions to Make String Balanced"
date = "2020-04-19"
description = "Solution to Leetcode 1653"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), bcnt = 0;
        vector<int> dp(n + 1, 0);
        for(int i = 0; i < n; i++) {
            char a = s[i];
            if(a == 'a') {                
                dp[i + 1] = min(dp[i] + 1, bcnt);
            } else {
                bcnt++;
                dp[i + 1] = dp[i];
            }
        }
        return dp[n];
    }
};
{{< /highlight >}}


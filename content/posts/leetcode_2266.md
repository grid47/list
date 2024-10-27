
+++
authors = ["Yasir"]
title = "Leetcode 2266: Count Number of Texts"
date = "2018-08-15"
description = "Solution to Leetcode 2266"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-number-of-texts/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
    int mod = 1e9 + 7;
public:
    int countTexts(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] % mod;
            if(i > 1 && s[i - 1] == s[i - 2]) {
                dp[i] = (dp[i] + dp[i - 2]) % mod;
                if(i > 2 && s[i - 1] == s[i - 3]) {
                    dp[i] = (dp[i] + dp[i - 3]) % mod;
                    if(i > 3 && (s[i-1]=='7' || s[i-1]=='9') && s[i - 1] == s[i - 4]) {
                        dp[i] = (dp[i] + dp[i - 4]) % mod;                        
                    }
                }
            }
        }

        return dp[n];
    }
};
{{< /highlight >}}


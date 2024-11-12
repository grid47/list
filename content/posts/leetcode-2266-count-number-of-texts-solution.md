
+++
authors = ["grid47"]
title = "Leetcode 2266: Count Number of Texts"
date = "2024-03-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2266: Count Number of Texts in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-number-of-texts/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2266.md" >}}
---
{{< youtube LdM0WLfhF_4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #2269: Find the K-Beauty of a Number](https://grid47.xyz/posts/leetcode-2269-find-the-k-beauty-of-a-number-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

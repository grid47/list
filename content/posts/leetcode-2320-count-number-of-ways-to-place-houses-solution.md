
+++
authors = ["grid47"]
title = "Leetcode 2320: Count Number of Ways to Place Houses"
date = "2024-03-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2320: Count Number of Ways to Place Houses in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-number-of-ways-to-place-houses/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {

    long long mod = 1000000007;

public:

    typedef long long ll;

    vector<vector<int>> dp;
    int countHousePlacements(int n) {
        
        dp.resize(n + 1, vector<int> (2, -1));
        
        ll res = ( rec(n, 0) + rec(n, 1) ) % mod;

        return (res * res ) % mod;
    }

    int rec(int n, bool filled) {
        if(n == 1) return 1;
        
        if(dp[n][filled] != -1)
            return dp[n][filled];

        if(filled)  return dp[n][filled] = rec(n - 1, !filled);
        else        return dp[n][filled] = ( rec(n - 1, filled) + rec(n - 1, !filled) ) % mod;
    }

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2320.md" >}}
---
{{< youtube 9K92zYtgjrk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #2325: Decode the Message](https://grid47.xyz/posts/leetcode-2325-decode-the-message-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}


+++
authors = ["Crafted by Me"]
title = "Leetcode 2320: Count Number of Ways to Place Houses"
date = "2018-06-27"
description = "In-depth solution and explanation for Leetcode 2320: Count Number of Ways to Place Houses in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}



+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2466: Count Ways To Build Good Strings"
date = "2018-01-28"
description = "Solution to Leetcode 2466"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-ways-to-build-good-strings/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    int mod = 1e9 + 7;
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        
        vector<int> dp(high + 1, -1);
        int ans = 0;
        for(int i = low; i <= high; i++) {
            ans = (ans + score(i, dp, zero, one)) % mod;
        }
        return ans;
    }

    int score(int target, vector<int> &dp, int zero, int one) {
        if(target == 0)      return 1;
        if(target < 1 )      return 0;
        if(dp[target] != -1) return dp[target];

        long long sum = score(target - zero, dp, zero, one) + score(target - one, dp, zero, one);

        return dp[target] = sum % mod;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


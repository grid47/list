
+++
authors = ["Crafted by Me"]
title = "Leetcode 879: Profitable Schemes"
date = "2022-06-06"
description = "Solution to Leetcode 879"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/profitable-schemes/description/)

---

{{< youtube 2aqdSV_tr-A >}}

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    int profitableSchemes(int n, int mnp, vector<int>& group, vector<int>& profit) {
        vector<vector<int>> dp(mnp + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for(int k = 0; k < profit.size(); k++) {
            int p = profit[k], g = group[k];
            for(int i = mnp; i >= 0; i--)
            for(int j= n - g; j >= 0; j--)
                dp[min(i + p, mnp)][j + g] = (dp[min(i + p, mnp)][j + g] + dp[i][j]) % mod;
        }
        int ret = 0;
        for(int x: dp[mnp]) ret = (ret + x) % mod;
        
        return ret;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/879.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


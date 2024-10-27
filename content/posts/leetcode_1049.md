
+++
authors = ["Yasir"]
title = "Leetcode 1049: Last Stone Weight II"
date = "2021-12-14"
description = "Solution to Leetcode 1049"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/last-stone-weight-ii/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {

        int sum = 0;
        for(int x: stones) sum += x;

        int n = stones.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, 0));

        for (int i = 1; i < n + 1  ; i++)
        for (int j = 0; j < sum / 2 + 1; j++) {
            if(j >= stones[i - 1]) 
                 dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
            else dp[i][j] = dp[i - 1][j];
        }

        return sum - 2 * dp[n][sum / 2];
    }
};
{{< /highlight >}}


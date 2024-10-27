
+++
authors = ["Yasir"]
title = "Leetcode 887: Super Egg Drop"
date = "2022-05-25"
description = "Solution to Leetcode 887"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/super-egg-drop/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        int m = 0;
        while (dp[m][K] < N) {
            m++;
            for (int k = 1; k <= K; ++k)
                dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
        }
        return m;
    }
};
{{< /highlight >}}


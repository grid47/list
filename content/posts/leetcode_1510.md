
+++
authors = ["Yasir"]
title = "Leetcode 1510: Stone Game IV"
date = "2020-09-09"
description = "Solution to Leetcode 1510"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/stone-game-iv/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k * k <= i; ++k) {
                if (!dp[i - k * k]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
{{< /highlight >}}


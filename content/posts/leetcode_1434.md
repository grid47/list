
+++
authors = ["Crafted by Me"]
title = "Leetcode 1434: Number of Ways to Wear Different Hats to Each Other"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1434: Number of Ways to Wear Different Hats to Each Other in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int n, M = 1e9 + 7;
    
    int dfs(vector<vector<int>>& hatsToPeople, vector<vector<int>>& dp, int hat, int mask) {
        if (mask == (1 << n) - 1) return 1;
        if (hat > 40) return 0;
        if (dp[mask][hat] != -1) return dp[mask][hat];
        long res = dfs(hatsToPeople, dp, hat + 1, mask);
        for (auto& person: hatsToPeople[hat]) {
            if ((1 << person) & mask) continue;
            (res += dfs(hatsToPeople, dp, hat + 1, mask | (1 << person))) %= M;
        }
        return dp[mask][hat] = res;
    }
    
    int numberWays(vector<vector<int>>& hats) {
        n = hats.size();
        vector<vector<int>> hatsToPeople(41);
        for (int i = 0; i < n; i++) {
            for (auto &h : hats[i]) {
                hatsToPeople[h].push_back(i);
            }
        }
        vector<vector<int>> dp(1 << n, vector<int>(41, -1));
        return dfs(hatsToPeople, dp, 1, 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1434.md" >}}
---
{{< youtube SlwENy96xdE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1435: Create a Session Bar Chart](https://grid47.xyz/posts/leetcode_1435) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}


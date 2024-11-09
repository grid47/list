
+++
authors = ["grid47"]
title = "Leetcode 1140: Stone Game II"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1140: Stone Game II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming","Prefix Sum","Game Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/stone-game-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    /*
    
    Taking postfix sum to count pile is new concept - residual count
    
    Thinking like, I had taken this much and pick what you
    require out of remaining, from how much ever you picked
    the rest is mine
    
    each call is others turn
    
    */
    vector<int> piles;
    vector<vector<int>> memo;
    int n;
    int dp(int idx, int m) {
        if(idx + 2* m >= piles.size()) return piles[idx];
        if(memo[idx][m] != -1) return memo[idx][m];
        int ans = 0;
        int tmp = 0;
        for(int x = 1; x <= 2 * m; x++) {
            int tmp = piles[idx] - piles[idx + x];
            ans = max(ans, tmp + piles[idx + x] - dp(idx + x, max(m, x)) );
        }
        return memo[idx][m] = ans;
    }
    int stoneGameII(vector<int>& p) {
        n = p.size();
        piles = p;
        memo.resize(n, vector<int>(n, -1));
        for(int i = p.size() - 2; i >= 0; i--)
            piles[i] += piles[i + 1];
        return dp(0, 1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1140.md" >}}
---
{{< youtube I-z-u0zfQtg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1143: Longest Common Subsequence](https://grid47.xyz/posts/leetcode-1143-longest-common-subsequence-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

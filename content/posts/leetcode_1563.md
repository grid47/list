
+++
authors = ["Crafted by Me"]
title = "Leetcode 1563: Stone Game V"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1563: Stone Game V in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/stone-game-v/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int n;
    vector<int> sv, sum;
    vector<vector<int>> memo;
    int dp(int l, int r) {
        
        if(l == r) return 0;
        
        if(memo[l][r] != -1) return memo[l][r];
        
        int ans = 0;
        for(int i = l; i < r; i++) {
            int left = (sum[i + 1] - sum[l]);
            int right = (sum[r + 1] - sum[i + 1]);

            if(left > right) {
                ans = max(ans, right + dp(i + 1, r));
            } else if(left < right) {
                ans = max(ans, left  + dp(l, i));
            } else {
                ans = max(ans, right + dp(i + 1, r));
                ans = max(ans, left  + dp(l, i));
            }
        }
        
        return memo[l][r] = ans;
    }
    
    int stoneGameV(vector<int>& sv) {
        n = sv.size();
        this->sv = sv;
        sum.resize(sv.size() + 1, 0);
        for(int i = 0; i < n; i++)
            sum[i + 1] = sum[i] + sv[i];
        memo.resize(n, vector<int>(n, -1));
        return dp(0, n - 1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1563.md" >}}
---
{{< youtube 0Bbn3RbXjfQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1564: Put Boxes Into the Warehouse I](https://grid47.xyz/posts/leetcode_1564) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


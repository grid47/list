
+++
authors = ["grid47"]
title = "Leetcode 1563: Stone Game V"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1563: Stone Game V in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming","Game Theory"]
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1567: Maximum Length of Subarray With Positive Product](https://grid47.xyz/posts/leetcode_1567) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

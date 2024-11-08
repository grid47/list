
+++
authors = ["grid47"]
title = "Leetcode 1406: Stone Game III"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1406: Stone Game III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming","Game Theory"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/stone-game-iii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int n;
    vector<int> pox, memo;
    
    int dp(int idx) {
        if(idx == n) return 0;
        
        if(memo[idx] != -1) return memo[idx];
        
        int ans = INT_MIN;

        for(int i = 0; i < 3 && idx + i < n; i++) {
            int sum = pox[idx] - pox[idx + i + 1];
            ans = max(ans, sum + pox[idx + i + 1] - dp(idx + i + 1));
        }

        return memo[idx] = ans;
    }
    
    string stoneGameIII(vector<int>& sv) {

        n = sv.size();
        memo.resize(n, -1);
        pox.resize(n + 1, 0);
        for(int i = n - 1; i >= 0; i--)
            pox[i] = pox[i + 1] + sv[i];
        int net = pox[0];
        int alice = dp(0);
        // cout << net << " " << net % 2 << " " << alice << " " << net / 2;
        int bob = net - alice;
        if(bob == alice) return "Tie";
        if(alice > bob) return "Alice";
        return "Bob";
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1406.md" >}}
---
{{< youtube HsLG5QW9CFQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1409: Queries on a Permutation With Key](https://grid47.xyz/posts/leetcode_1409) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

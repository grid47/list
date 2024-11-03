
+++
authors = ["Crafted by Me"]
title = "Leetcode 1406: Stone Game III"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1406: Stone Game III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1407: Top Travellers](https://grid47.xyz/posts/leetcode_1407) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


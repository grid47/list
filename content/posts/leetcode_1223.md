
+++
authors = ["Crafted by Me"]
title = "Leetcode 1223: Dice Roll Simulation"
date = "2021-06-28"
description = "In-depth solution and explanation for Leetcode 1223: Dice Roll Simulation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/dice-roll-simulation/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    vector<int> rm;
    int n;
    int mem[5001][7][16];
    int dp(int idx, int prv, int cnt) {
        
        if(idx == n) return 1;
        if(mem[idx][prv + 1][cnt] != -1) return mem[idx][prv + 1][cnt];
        long ans = 0;
        for(int i = 0; i < rm.size(); i++) {
            if(i== prv && cnt < rm[i]) {
                ans = (ans + dp(idx + 1, i, cnt + 1)) % mod;
            } else if(i != prv) {
                ans = (ans + dp(idx + 1, i, 1)) % mod;                
            }
        }

        return mem[idx][prv + 1][cnt] = ans % mod;
    }
    
    int dieSimulator(int n, vector<int>& rollMax) {
        this-> n = n;
        rm = rollMax;
        memset(mem, -1, sizeof(mem));
        return dp(0, -1, 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1223.md" >}}
---


| Next : [LeetCode #1224: Maximum Equal Frequency](grid47.xyz/leetcode_1224) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


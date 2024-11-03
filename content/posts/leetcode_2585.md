
+++
authors = ["Crafted by Me"]
title = "Leetcode 2585: Number of Ways to Earn Points"
date = "2017-10-05"
description = "In-depth solution and explanation for Leetcode 2585: Number of Ways to Earn Points in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-ways-to-earn-points/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    int n;
    vector<vector<int>> types, memo;
    
    int dp(int idx, int hit) {
        if(idx == n) return hit == 0? 1: 0;
        if(hit == 0) return 1;
        if(memo[idx][hit] != -1) return memo[idx][hit];
        long ans = 0;
        for(int i = 0; i <= types[idx][0]; i++) {
            if(hit >= types[idx][1] * i) {
                ans = (ans + dp(idx + 1, hit - types[idx][1] * i)) % mod;
            }
        }
        return memo[idx][hit] = ans;
    }
    
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        n = types.size();
        memo.resize(51, vector<int>(1001, -1));
        this->types = types;
        return dp(0, target);
    }
};
{{< /highlight >}}


---


| Next : [LeetCode #2586: Count the Number of Vowel Strings in Range](grid47.xyz/leetcode_2586) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


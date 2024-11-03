
+++
authors = ["Crafted by Me"]
title = "Leetcode 1416: Restore The Array"
date = "2020-12-17"
description = "In-depth solution and explanation for Leetcode 1416: Restore The Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/restore-the-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string s;
    int k;
    vector<int> memo;
    int mod = (int) 1e9 + 7;
    int dp(int idx) {
        if(idx == s.size()) return 1;
        if(s[idx] == '0') return 0;
        
        if(memo[idx] != -1) return memo[idx];
        long num = 0;
        long ans = 0;
        for(int i = idx; i < s.size(); i++) {
            num = num * 10 + s[i] - '0';
            if(num > k) break;
            ans += dp(i + 1);
            ans %= mod;
        }
        return memo[idx] = ans % mod;
    }
    int numberOfArrays(string s, int k) {
        this->s = s;
        this->k = k;
        memo.resize(s.size(), -1);
        return dp(0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1416.md" >}}
---
{{< youtube Kw6_4htJ9Sw >}}

| Next : [LeetCode #1417: Reformat The String](grid47.xyz/leetcode_1417) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


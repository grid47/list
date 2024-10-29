
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1416: Restore The Array"
date = "2020-12-14"
description = "Solution to Leetcode 1416"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


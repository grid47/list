
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1639: Number of Ways to Form a Target String Given a Dictionary"
date = "2020-05-04"
description = "Solution to Leetcode 1639"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string hit;
    int mod = (int) 1e9 + 7;
    vector<vector<int>> frq;
    int memo[1001][1001];
    
    int dp(int fidx, int hidx) {
        if(hidx == hit.size()) return 1;
        if(fidx == frq.size()) return 0;
        
        if(memo[fidx][hidx] != -1) return memo[fidx][hidx];
        
        long ans = dp(fidx + 1, hidx);
        
        int ch = hit[hidx] - 'a';
        if(frq[fidx][ch] > 0) {
            ans = (ans + (long)(frq[fidx][ch] % mod) * (dp(fidx + 1, hidx + 1) % mod)) % mod;
        }
        
        return memo[fidx][hidx] = ans % mod;
    }
    
    int numWays(vector<string>& words, string target) {
        hit = target;
        frq.resize(words[0].size(), vector<int>(26, 0));
        
        for(string s: words)
            for(int i = 0; i < s.size(); i++) {
                frq[i][s[i] - 'a']++;
            }
        memset(memo, -1, sizeof(memo));
        return dp(0, 0);
        
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


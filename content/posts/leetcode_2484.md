
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2484: Count Palindromic Subsequences"
date = "2018-01-10"
description = "Solution to Leetcode 2484"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-palindromic-subsequences/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int mod = (int) 1e9 + 7;
    
    int countPalindromes(string s) {
        
        int pre[10001][10][10], suf[10001][10][10], cnt[10] = {};
        memset(pre, 0, sizeof(pre));
        
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            int c = s[i] - '0';
            if(i)
                for(int j = 0; j < 10; j++)
                for(int k = 0; k < 10; k++) {
                    pre[i][j][k] = pre[i - 1][j][k];
                    if(k == c) pre[i][j][k] += cnt[j];
                }
            cnt[c]++;
        }
        
        memset(suf, 0, sizeof(suf));
        memset(cnt, 0, sizeof(cnt));        
        
        for(int i = n - 1; i >= 0; i--) {
            int c = s[i] - '0';
            if(i < n - 1)
                for(int j = 0; j < 10; j++)
                for(int k = 0; k < 10; k++) {
                    suf[i][j][k] = suf[i + 1][j][k];
                    if(k == c) suf[i][j][k] += cnt[j];
                }
            cnt[c]++;
        }
        long long ans = 0;
        for(int i = 2; i < n - 2; i++)
            for(int j = 0; j < 10; j++)
            for(int k = 0; k < 10; k++)
                ans = (ans + 1LL * pre[i - 1][j][k] * suf[i + 1][j][k]) % mod;
        
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


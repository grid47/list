
+++
authors = ["Yasir"]
title = "Leetcode 664: Strange Printer"
date = "2023-01-02"
description = "Solution to Leetcode 664"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/strange-printer/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<vector<int>> memo;
    string s;
    
    int dp(int l, int r) {
        if(l > r) return 0;
        
        if(memo[l][r] != -1) return memo[l][r];
        
        int ans = 1 + dp(l + 1, r);
        
        for(int i = l + 1; i <= r; i++) {
            if(s[i] == s[l])
            ans = min(ans, dp(l + 1, i) + dp(i + 1, r));
        }
        
        
        return memo[l][r] = ans;
    }
    
    
    int strangePrinter(string s) {
        /*
              _ _ _ _     _
            _ _ _ _ _ _ _  
        _ _ _ _ _ _ _ _ _ _
        */
        memo.resize(s.size(), vector<int>(s.size(), -1));
        this->s = s;
        return dp(0, s.size() - 1);
    }
};
{{< /highlight >}}


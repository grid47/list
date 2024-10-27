
+++
authors = ["Yasir"]
title = "Leetcode 2002: Maximum Product of the Length of Two Palindromic Subsequences"
date = "2019-05-06"
description = "Solution to Leetcode 2002"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int n;
    string p;
    
    bool pal(string &s) {
        int i = 0, j = s.size() - 1;
        while(i <= j) {
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
    
    int dp(int idx, string &s1, string &s2) {
        if(idx == n) {
            if(pal(s1) && pal(s2)) {
                return s1.size() * s2.size();
            }
            return 0;
        }

        s1.push_back(p[idx]);
        int ans = dp(idx + 1, s1, s2);
        s1.pop_back();        
        
        s2.push_back(p[idx]);        
        ans = max(ans, dp(idx + 1, s1, s2));
        s2.pop_back();        
        
        ans = max(ans, dp(idx + 1, s1, s2));
        
        // return mp[idx][s1][s2] = ans;
        return ans;        
    }
    
    
    int maxProduct(string s) {
        p = s;
        n = s.size();
        string s1 = "", s2 = "";
        return dp(0, s1, s2);
    }
};
{{< /highlight >}}


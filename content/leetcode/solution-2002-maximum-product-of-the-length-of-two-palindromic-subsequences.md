
+++
authors = ["grid47"]
title = "Leetcode 2002: Maximum Product of the Length of Two Palindromic Subsequences"
date = "2024-04-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2002: Maximum Product of the Length of Two Palindromic Subsequences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Backtracking","Bit Manipulation","Bitmask"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "aoHbYlO8vDg"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2002.md" >}}
---
{{< youtube aoHbYlO8vDg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2006: Count Number of Pairs With Absolute Difference K](https://grid47.xyz/leetcode/solution-2006-count-number-of-pairs-with-absolute-difference-k/) |
| --- |

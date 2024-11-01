
+++
authors = ["Crafted by Me"]
title = "Leetcode 639: Decode Ways II"
date = "2023-02-02"
description = "Solution to Leetcode 639"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/decode-ways-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> memo;
    int mod = (int) 1e9 + 7;
    int numDecodings(string s) {
        memo.resize(s.size(), -1);
        return !s.size()? 0: ways(0, s);
    }
    
    long long ways(int i, string &s) {
        if(i >= s.size()) return 1;
        if(s[i] == '0') return memo[i] = 0; // no char matching with '0*'
        
        if(memo[i] != -1) return memo[i];
        
        long long res = ways(i + 1, s);
        
        if(s[i] == '*') {
            res *= 9;
            
            if(i < s.size() - 1 && s[i + 1] >= '0' && s[i+1] <= '9') {
                res += ways(i + 2, s);
            }
            
            if(i < s.size() - 1 && s[i + 1] == '*') {
                res += 9 * ways(i + 2, s);
            }
            
            if(i < s.size() - 1 && s[i + 1] >= '0' && s[i+1] <= '6') {
                res += ways(i + 2, s);
            }
            
            if(i < s.size() - 1 && s[i + 1] == '*') {
                res += 6 * ways(i + 2, s);
            }            
        } else if(s[i] == '1' && i < s.size() - 1) {
            if(s[i+1] >= '0' && s[i+1] <= '9')
                res += ways(i + 2, s);
            
            if(s[i+1] == '*')
                res += 9 * ways(i + 2, s);
        } else if(s[i] == '2' && i < s.size() - 1) {
            if(s[i+1] >= '0' && s[i+1] <= '6')
                res += ways(i + 2, s);
            
            if(s[i+1] == '*')
                res += 6* ways(i + 2, s);
        }
        res = res % mod;
        
        return memo[i] = res;
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/639.md" >}}
- by gpt
        
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}



+++
authors = ["Yasir"]
title = "Leetcode 2140: Solving Questions With Brainpower"
date = "2018-12-19"
description = "Solution to Leetcode 2140"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/solving-questions-with-brainpower/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<vector<int>> qns;
    vector<long long> mem;
    
    long long dp(int idx) {
        if(idx >= qns.size()) return 0;
        
        if(mem[idx] != -1) return mem[idx];
        
        long long ans = dp(idx + 1);
        
        ans = max(ans, (long long) qns[idx][0] + dp(idx + 1+ qns[idx][1]));
        
        return mem[idx] = ans;
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        qns = questions;
        
        mem.resize(qns.size(), -1);
        return dp(0);
        
    }
};
{{< /highlight >}}


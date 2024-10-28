
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2140: Solving Questions With Brainpower"
date = "2018-12-20"
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

{{< highlight cpp >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


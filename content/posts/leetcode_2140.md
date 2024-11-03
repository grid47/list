
+++
authors = ["Crafted by Me"]
title = "Leetcode 2140: Solving Questions With Brainpower"
date = "2018-12-24"
description = "In-depth solution and explanation for Leetcode 2140: Solving Questions With Brainpower in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---
{{< youtube yPaLLSEDlX4 >}}

| Next : [LeetCode #2141: Maximum Running Time of N Computers](grid47.xyz/leetcode_2141) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


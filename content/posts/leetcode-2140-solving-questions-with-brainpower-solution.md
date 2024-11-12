
+++
authors = ["grid47"]
title = "Leetcode 2140: Solving Questions With Brainpower"
date = "2024-04-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2140: Solving Questions With Brainpower in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2140.md" >}}
---
{{< youtube yPaLLSEDlX4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2144: Minimum Cost of Buying Candies With Discount](https://grid47.xyz/posts/leetcode-2144-minimum-cost-of-buying-candies-with-discount-solution/) |
| --- |

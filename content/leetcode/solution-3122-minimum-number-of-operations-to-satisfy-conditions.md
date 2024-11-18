
+++
authors = ["grid47"]
title = "Leetcode 3122: Minimum Number of Operations to Satisfy Conditions"
date = "2023-12-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3122: Minimum Number of Operations to Satisfy Conditions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-operations-to-satisfy-conditions/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int m, n;
    vector<vector<int>> frq, mem;
    
    int dp(int i, int prv) {
        if(i == frq.size()) return 0;
        if(mem[i][prv + 1] != -1) return mem[i][prv + 1];

        int ans = INT_MAX;
        for(int j = 0; j <= 9; j++) {
            if(j == prv) continue;
            ans = min(ans, m - frq[i][j] + dp(i + 1, j));
        }

        return mem[i][prv + 1] = ans;
    }
    
    int minimumOperations(vector<vector<int>>& grid) {
        
        m = grid.size(), n = grid[0].size();
        
        frq.resize(n, vector<int>(10, 0));
        mem.resize(n, vector<int>(11, -1));
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            frq[i][grid[j][i]]++;
        }
        
        return dp(0, -1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3122.md" >}}
---
{{< youtube LLDe54TfbMs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #3127: Make a Square with the Same Color](https://grid47.xyz/leetcode/solution-3127-make-a-square-with-the-same-color/) |
| --- |

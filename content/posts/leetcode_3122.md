
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 3122: Minimum Number of Operations to Satisfy Conditions"
date = "2016-04-13"
description = "Solution to Leetcode 3122"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

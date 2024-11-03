
+++
authors = ["Crafted by Me"]
title = "Leetcode 3122: Minimum Number of Operations to Satisfy Conditions"
date = "2016-04-16"
description = "In-depth solution and explanation for Leetcode 3122: Minimum Number of Operations to Satisfy Conditions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---


"| 3123: Find Edges in Shortest Paths |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


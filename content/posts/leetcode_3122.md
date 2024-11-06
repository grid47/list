
+++
authors = ["Crafted by Me"]
title = "Leetcode 3122: Minimum Number of Operations to Satisfy Conditions"
date = "2024-11-01"
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


---
{{< youtube LLDe54TfbMs >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #3123: Find Edges in Shortest Paths](https://grid47.xyz/posts/leetcode_3123) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

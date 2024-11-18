
+++
authors = ["grid47"]
title = "Leetcode 877: Stone Game"
date = "2024-08-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 877: Stone Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming","Game Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/stone-game/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> p;
    int n;
    
    map<int, map<int,int>> memo;
    
    bool dp(int i, int j) {
        if(i == j) return p[i];
        
        if(memo.count(i) && memo[i].count(j)) return memo[i][j];
        
        return memo[i][j] = max(p[i] - dp(i + 1, j), p[j] - dp(i, j - 1)) ;
        
    }
    
    bool stoneGame(vector<int>& piles) {
        this->p = piles;
        n = piles.size();
        return dp(0, n - 1) >= 0;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/877.md" >}}
---
{{< youtube jGmq8d4cIx0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #880: Decoded String at Index](https://grid47.xyz/leetcode/solution-880-decoded-string-at-index/) |
| --- |

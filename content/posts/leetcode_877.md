
+++
authors = ["Yasir"]
title = "Leetcode 877: Stone Game"
date = "2022-06-03"
description = "Solution to Leetcode 877"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/stone-game/description/)

---

**Code:**

{{< highlight html >}}
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


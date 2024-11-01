
+++
authors = ["Crafted by Me"]
title = "Leetcode 877: Stone Game"
date = "2022-06-09"
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

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


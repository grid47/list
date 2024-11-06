
+++
authors = ["Crafted by Me"]
title = "Leetcode 877: Stone Game"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #878: Nth Magical Number](https://grid47.xyz/posts/leetcode_878) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

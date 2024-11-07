
+++
authors = ["Crafted by Me"]
title = "Leetcode 1690: Stone Game VII"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1690: Stone Game VII in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming","Game Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/stone-game-vii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int memo[1001][1001] = {};
    int dp(vector<int>& s, int i, int j, int sum) {
        
        if(i == j) {
            return 0;
        }
        
        
        return memo[i][j] ? memo[i][j] : memo[i][j] = max(sum - s[i] - dp(s, i + 1, j, sum - s[i]),
                                            sum - s[j] - dp(s, i, j - 1, sum - s[j]));
    }
    
    int stoneGameVII(vector<int>& s) {
        int n = s.size();
        return dp(s, 0,n-1, accumulate(begin(s), end(s), 0));
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1690.md" >}}
---
{{< youtube cOGliK5brbQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1693: Daily Leads and Partners](https://grid47.xyz/posts/leetcode_1693) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

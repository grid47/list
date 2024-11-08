
+++
authors = ["grid47"]
title = "Leetcode 115: Distinct Subsequences"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 115: Distinct Subsequences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/distinct-subsequences/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int memo[1001][1001];
    string s, t;
    int dp(int i, int j) {
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        int res = 0;
        if(s[i] == t[j]) {
            res = dp(i + 1, j+ 1) + dp(i + 1, j);
        } else res = dp(i + 1, j);
        
        return memo[i][j] = res;
    }
    int numDistinct(string s, string t) {
        this->s = s;
        this->t = t;
        memset(memo, -1, sizeof(memo));
        return dp(0, 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/115.md" >}}
---
{{< youtube -RDzMJ33nx8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #116: Populating Next Right Pointers in Each Node](https://grid47.xyz/posts/leetcode_116) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
